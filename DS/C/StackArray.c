#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int *arr;
    int top;
    int size;
} Stack;

void initialize(Stack *stack, int x)
{
    stack->size = x;
    stack->arr = (int *)malloc(stack->size * sizeof(int));
    stack->top = -1;
}

bool isEmpty(Stack *stack)
{
    if (stack->top == -1)
        return true;
    return false;
}

bool isFull(Stack *stack)
{
    if (stack->top == stack->size - 1)
        return true;
    return false;
}

void push(Stack *stack, int x)
{
    if (isFull(stack))
    {
        printf("Stack is full\n");
        return;
    }
    stack->top += 1;
    stack->arr[stack->top] = x;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    stack->top -= 1;
    return stack->arr[stack->top + 1];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main()
{
    Stack *stk = (Stack *)malloc(sizeof(Stack));
    initialize(stk, 5);
    printf("%d\n", peek(stk));
    printf("%d\n", pop(stk));
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    push(stk, 4);
    push(stk, 5);
    push(stk, 5);
    // push(stk, 5);
    printf("%d\n", pop(stk));
    printf("%d\n", pop(stk));
    printf("%d\n", peek(stk));
    printf("%d\n", pop(stk));

    return 0;
}