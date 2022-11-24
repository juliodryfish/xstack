#ifndef XSTACK_H
#define XSTACK_H
#include <stdio.h>
#include <stdbool.h>


#define STACK_SIZE (1024 * 4)

typedef void * element_t;
typedef element_t* (element_ptr);

typedef struct {
    element_ptr xstack[STACK_SIZE];
    int N;
}xstack_t;
typedef xstack_t * (xstack_ptr);


void xstack_push(xstack_ptr stack,element_ptr e) {
    if(stack && stack->N < STACK_SIZE)
    stack->xstack[stack->N++] = e;
}
element_ptr xstack_pop(xstack_ptr stack) {
    if(stack && stack->N) return stack->xstack[--(stack->N)];
    return 0;
}

void show_xstack(xstack_ptr stack){
    if(!stack) return;
    for(int i = 0; i < stack->N; ++i) {
        printf("%d\n",  *((int *)stack->xstack[i]));
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

    xstack_t stack;
    stack.N = 0;

    int arr[5] = {1, 2, 3, 4, 5};

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
    printf(":%d\n", *((int *)xstack_top(&stack)));
    return 0;
}

#endif