#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1600
#define NULLKEY -32768

typedef struct {
    int* array;
    int top; 
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* minstack = (MinStack*)malloc(sizeof(MinStack));
    minstack->array = (int*)malloc(sizeof(int)*MAXSIZE);
    minstack->top = -1;
    return minstack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top >= MAXSIZE-1) {
    } else if (obj->top == -1) {
        obj->top++;
        obj->array[obj->top] = x;
        obj->top++;
        obj->array[obj->top] = x;
    } else {
        int min = obj->array[obj->top];
        if (min > x) {
            min = x;
        }
        obj->top++;
        obj->array[obj->top] = x;
        obj->top++;
        obj->array[obj->top] = min;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) {
    } else {
        obj->top = obj->top-2;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top == -1) {
        return NULLKEY;
    } else {
        return obj->array[obj->top-1];
    }
}

int minStackGetMin(MinStack* obj) {
    if (obj->top == -1) {
        return NULLKEY;
    } else {
        return obj->array[obj->top];
    }
}

void minStackFree(MinStack* obj) {
    free(obj->array);
    obj->array=NULL;
    free(obj);
    obj=NULL;
}

int main()
{
    MinStack* obj = minStackCreate();
    minStackPush(obj, 5);
    minStackPush(obj, 7);
    minStackPush(obj, 2);
    minStackPush(obj, 4);
    minStackPop(obj);
    int param_3 = minStackTop(obj);
    int param_4 = minStackGetMin(obj);
    minStackFree(obj);
}
