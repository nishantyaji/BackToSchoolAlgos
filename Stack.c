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

// Helper function. Not a core function.
void display(Stack * stack) {
    Elem * pres = stack->head;
    printf("\nContents of len: %d", stack->length);
    while(pres != NULL) {
        printf("\n%d", pres->value);
        pres = pres->next;
    }
    printf("\n");
}

// Helper function. Not a core function.
Elem * getElem(int a) {
    Elem * elem = (Elem *) malloc(sizeof(Elem));
    elem->prev = NULL;
    elem->next = NULL;
    elem->value = a;
    return elem;
}

int main()
{
    printf("Hello World");
    Stack * st = (Stack *) malloc(sizeof(Stack));
    push(st, getElem(1));
    display(st);
    push(st, getElem(2));
    display(st);
    push(st, getElem(5));
    display(st);
    int stLen = st->length;
    int i = 0;
    for(i = 0; i < stLen; i++) {
        Elem * popped = pop(st);
        printf("\nPopped: %d", popped->value);
    }
    push(st, getElem(2));
    display(st);
    push(st, getElem(5));
    display(st);
    
    return 0;
}
