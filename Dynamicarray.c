#include<stdio.h>
#include<stdlib.h>

#define INIT_CAPACITY 1

typedef struct stack{
    int top;
    int capacity;
    int *array;
} Stack;

int push(Stack *stack, int value){
    if(stack->top == stack->capacity -1){
        stack->capacity *= 2;
        stack->array = (int*)realloc(stack->array,stack->capacity * sizeof(int));
    }
    stack->array[++stack->top] = value;
    return value;
}

int checkUnderflow(Stack *stack){
    if(stack->top == -1){
        printf("Underflow\n");
        return 1;
    }
    return 0;
}

int pop(Stack *stack){
    if(checkUnderflow(stack)){
        return -1;
    }
    return stack->array[stack->top--];
}

int display(Stack *stack){
    if(checkUnderflow(stack)){
        return -1;
    }
    for (int i = 0; i < stack->top; i++)
    {
        printf(" %d ", stack->array[i]);
    }
}

void main(){
    Stack stack;
    stack.top = -1;
    stack.capacity = INIT_CAPACITY;
    stack.array = (int*)malloc(INIT_CAPACITY * sizeof(int));

    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    display(&stack);
    free(stack.array);
}

