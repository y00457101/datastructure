#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*用数组存储栈*/
#define MAXSIZE 20

typedef int elementType;    //数据类型

typedef struct {
    elementType* array;
    elementType top;
} Stack;

Stack* StackCreate() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack) {
        stack->array = (elementType*)malloc(MAXSIZE * sizeof(elementType*));
        stack->top = 0;
    }

    return stack;
}

void StackPush(Stack* s, elementType x) {
    if (s->top >= MAXSIZE-1)
        return;
    s->array[s->top++] = x;
}

void StackPop(Stack* s) {
    if (s->top == 0)
        return;
    s->top--;
}

int StackTop(Stack* s) {
    if (s->top == 0)
        return -1;
    return s->array[s->top - 1];
}

void StackFree(Stack* s) {
    if (s) {
        free(s->array);
        free(s);
    }

}

int main()
{
    Stack* stack = StackCreate();
    StackPush(stack, 5);
    StackPush(stack, 6);
    StackPush(stack, 7);
    StackPop(stack);
    elementType param_3 = StackTop(stack);
    StackFree(stack);
    return 0;
}
