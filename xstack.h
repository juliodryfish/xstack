#ifndef XSTACK_H
#define XSTACK_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define YLW "\e[0;33m"
#define CRT "\e[0m"

//#define STACK_SIZE (1024 * 4)

typedef void * element_t;
typedef element_t* (element_ptr);
typedef struct {
    element_ptr * xstack;
    int STACK_SIZE;
    int N;
}xstack_t;
typedef xstack_t * (xstack_ptr);

void xstack_start(xstack_ptr stack, int stack_size) {
    //...
    stack->STACK_SIZE = stack_size;
    stack->xstack = (element_ptr *) malloc(stack->STACK_SIZE * sizeof(element_ptr));
    stack->N = 0;
}

void xstack_end(xstack_ptr stack) {
    free(stack->xstack);
}

void xstack_push(xstack_ptr stack, element_ptr e) {
    if(stack && stack->N < stack->STACK_SIZE)
    stack->xstack[stack->N++] = e;
}
element_ptr xstack_pop(xstack_ptr stack) {
    if(stack && stack->N) return stack->xstack[--(stack->N)];
    return 0;
}

void show_xstack(xstack_ptr stack){
    if(!stack) return;
    for(int i = 0; i < stack->N; ++i) {
        printf(YLW"%d:%p\n"CRT,  *((int *)stack->xstack[i]), ((int *)stack->xstack[i]));
    }
}
bool xstack_empty(xstack_ptr stack) {
    if(stack) return (!stack->N);
    return true;
}
int xstack_size(xstack_ptr stack) {
    if(stack) return stack->N;
    return 0;
}

element_ptr xstack_top(xstack_ptr stack) {
    if(stack && stack->N) return stack->xstack[stack->N - 1];
    return 0;
}


int main() {

    // TODO: allocations fail check
    // TODO: split code into files

    xstack_t stack;
    xstack_start(&stack, 1024 * 4);


    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; ++i) {
        printf("%d:%p\n", arr[i], &arr[i]);
    }

    xstack_push(&stack, (element_ptr)&arr[0]);
    xstack_push(&stack, (element_ptr)&arr[2]);
    xstack_push(&stack, (element_ptr)&arr[4]);
    show_xstack(&stack);
    printf(":%d\n", *((int *)xstack_pop(&stack)));
    printf(":%d\n", *((int *)xstack_pop(&stack)));
    printf(":%d\n", *((int *)xstack_pop(&stack)));
    show_xstack(&stack);
    xstack_push(&stack, (element_ptr)&arr[0]);
    xstack_push(&stack, (element_ptr)&arr[2]);
    xstack_push(&stack, (element_ptr)&arr[4]);
    printf(":%d\n", *((int *)xstack_top(&stack)));
    printf(">%d\n", xstack_size(&stack));
    printf(">%d\n", xstack_empty(&stack));
    printf(":%d\n", *((int *)xstack_pop(&stack)));
    printf(":%d\n", *((int *)xstack_pop(&stack)));
    printf(":%d\n", *((int *)xstack_pop(&stack)));
    printf(">%d\n", xstack_size(&stack));
    printf(">%d\n", xstack_empty(&stack));
    printf(":%d\n", ((int *)xstack_top(&stack)) ? *((int *)xstack_top(&stack)) : 0);

    xstack_end(&stack);

    return 0;
}

#endif