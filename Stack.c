#include <stdio.h>
#include <stdlib.h> 

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

void push(Stack * stack, int toAdd) {
    Elem * elem = (Elem *) malloc(sizeof(Elem));
    elem->value = toAdd;
    if(stack->length == 0) {
        stack->head = elem;
    } else{
        elem->prev = stack->end;
        stack->end->next = elem;
    }
    stack->end = elem;
    stack->length = stack->length + 1;
}

int pop(Stack * stack) {
    int returnVal;
    returnVal = stack->end->value;
    if(stack->end->prev != NULL)
        stack->end = stack->end->prev;
    stack->end->next = NULL;
    stack->length = stack->length - 1;
    return returnVal;
}

int display(Stack * stack) {
    Elem * pres = stack->head;
    printf("\nDisplaying contents of stack, len: %d, :", stack->length);
    while(pres != NULL) {
        printf("\n%d", pres->value);
        pres = pres->next;
    }
    printf("\n");
}

int main()
{
    printf("Hello World");
    Stack * st = (Stack *) malloc(sizeof(Stack));
    push(st, 1);
    display(st);
    push(st, 2);
    display(st);
    push(st, 5);
    display(st);
    int stLen = st->length;
    int i = 0;
    for(i = 0; i < stLen; i++) {
        int popped = pop(st);
        printf("\nPopped: %d", popped);
    }
    push(st, 2);
    display(st);
    push(st, 5);
    display(st);
    
    return 0;
}
