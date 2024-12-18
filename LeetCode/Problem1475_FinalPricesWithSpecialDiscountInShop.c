#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Elem{
    int value;
    struct Elem * prev;
    struct Elem * next;
} Elem;

typedef struct Stack {
  int length;
  struct Elem * head;
  struct Elem * end;
} Stack;

void push(Stack * stack, Elem * elem) {
    if(stack->length == 0) {
        stack->head = elem;
    } else{
        elem->prev = stack->end;
        stack->end->next = elem;
    }
    elem->next = NULL;
    stack->end = elem;
    stack->length = stack->length + 1;
}

Elem * pop(Stack * stack) {
    Elem * elem = (Elem *) malloc(sizeof(Elem));
    elem->value = stack->end->value;
    elem->prev = NULL;
    elem->next = NULL;
    if(stack->end->prev != NULL)
        stack->end = stack->end->prev;
    stack->end->next = NULL;
    stack->length = stack->length - 1;
    return elem;
}

void display(Stack * stack) {
    Elem * pres = stack->head;
    printf("\nContents of len: %d", stack->length);
    while(pres != NULL) {
        printf("\n%d", pres->value);
        pres = pres->next;
    }
    printf("\n");
}


int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    * returnSize = pricesSize;
    int * res = (int *)malloc(sizeof(int) *(* returnSize));
    
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->length = 0;
    int i = 0;
    for(i = pricesSize-1; i >=0; i--) {
         res[i] = prices[i];
         if(stack->length > 0) {
             while(stack->length > 0 && stack->end->value > prices[i]) {
                Elem * elem = pop(stack);
             }
             if(stack->length > 0) {
                 res[i] = prices[i] - stack->end->value;
             }
         }
         Elem * th = (Elem* )malloc(sizeof(Elem));
         th->prev = NULL;
         th->next = NULL;
         th->value = prices[i];
         push(stack, th);
    }
    return res;
}

int main()
{
    int s[5] = {8,4,6,2,3};
    int retSize = 0;
    int * ret = finalPrices(s, 5, &retSize);
    int i = 0;
    for(i = 0; i < retSize; i++) {
        printf("\n%d", ret[i]);
    }
}
