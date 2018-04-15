#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int top;
    int capacity;
    char *array;
};
struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = 128;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity -1;
}
int isEmpty(struct Stack * stack)
{
    return stack->top == -1;
}
void push(struct Stack * stack, char item)
{
    if(isFull(stack)) return;
    stack->array[++stack->top] = item;
}
char pop(struct Stack* stack)
{
    if(isEmpty(stack)) return ' ';
    return stack->array[stack->top--];
}


int main(void)
{
    int cases,isGood = 1;
    char parenth;
    struct Stack *stack = createStack();

    scanf("%d \n",&cases);
    while(cases--)
    {
        scanf("%c",&parenth);
        while(parenth != '\n')
        {
            if(parenth == '(' || parenth == '[')
            {
                push(stack,parenth);\
            }
            else
            {
                if(isEmpty(stack) && isGood)
                {
                    printf("No\n");
                    isGood = 0;
                }
                else
                {
                    if(isGood && ((parenth == ']' && pop(stack) == '(')  ||  (parenth == ')' && pop(stack) == '[')))
                    {
                        printf("No\n");
                        isGood = 0;
                    }
                }
            }
            scanf("%c",&parenth);
        }
        if(isGood && isEmpty(stack)) printf("Yes\n");
        else if(isGood) printf("No\n");
        isGood = 1;
        while(!isEmpty(stack))
        {
            pop(stack);
        }
    }


    return 0;
}
