#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Stack
{
    char *arr;
    int top;
    int size;
} Stack;

void initialize(Stack *stack, int x)
{
    stack->size = x;
    stack->arr = (char *)malloc(stack->size * sizeof(char));
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

void push(Stack *stack, char x)
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

char *peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return stack->arr;
    }
    return stack->arr + stack->top;
}
/**********************************************************/

bool isOpenBracket(char *s)
{
    if (*s == '(')
        return true;
    return false;
}

bool isCloseBracket(char *s)
{
    if (*s == ')')
        return true;
    return false;
}

bool isOperator(char *s)
{
    int operators[] = {'+', '*', '/', '-'};
    int n = 4;
    while (--n >= 0)
        if (operators[n] == *s)
            return true;
    return false;
}

bool checkPrecedence(char *left, char *right)
{
    char *operators = "+-*/";
    int precedence[] = {1, 1, 2, 2};
    int leftIndex = 0;
    int rightIndex = 0;
    int n = strlen(operators);
    int i;
    for (i = 0; i < n; i++)
    {
        if (operators[i] == *left)
            leftIndex = i;
        if (operators[i] == *right)
            rightIndex = i;
    }
    if (precedence[leftIndex] < precedence[rightIndex])
        return true;
    return false;
}

char *toPostFix(char *exp)
{
    int n = strlen(exp);
    int i;
    Stack *operators = (Stack *)malloc(sizeof(Stack));
    Stack *postFixExp = (Stack *)malloc(sizeof(Stack));
    initialize(operators, n);
    initialize(postFixExp, n);
    for (i = 0; i < n; i++)
    {
        if (isOpenBracket(exp + i))
            push(operators, exp[i]);
        else if (isCloseBracket(exp + i))
        {
            while (!isOpenBracket(peek(operators)))
                push(postFixExp, pop(operators));
            pop(operators);
        }
        else if (isOperator(exp + i))
        {
            while (!checkPrecedence(peek(operators), exp + i) && isOperator(peek(operators)))
                push(postFixExp, pop(operators));
            push(operators, *(exp + i));
        }
        else
            push(postFixExp, *(exp + i));
    }

    for (i = 0; i < n; i++)
        printf("%c ", operators->arr[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%c ", postFixExp->arr[i]);
    return exp;
}

int main()
{
    char *str = "(a*b+c*d/(e+f)-g)";

    // printf("%s", toPostFix(str));
    char *o = "+-/*=9";
    // printf("%d", isOperator(o+3));
    toPostFix(str);
    return 0;
}