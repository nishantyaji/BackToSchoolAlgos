#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Elem{
    int ch;
    int count;
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
    stack->end = elem;
    stack->length = stack->length + 1;
}

Elem * pop(Stack * stack) {
    Elem * elem = (Elem *) malloc(sizeof(Elem));
    elem->ch = stack->end->ch;
    elem->count = stack->end->count;
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
        printf("\n%d", pres->ch);
        pres = pres->next;
    }
    printf("\n");
}


char* repeatLimitedString(char* s, int repeatLimit) {
    int len = strlen(s);
    int i = 0;
    int * alphaCount = (int *) malloc(sizeof(int) * 26);

    for (i = 0; i < 26; i++) {
        alphaCount[i] = 0;
    }
    for (i = 0; i < len; i++) {
        int charValue = (int)(s[i]) - 97; // ascii of a = 97
        alphaCount[charValue]++;
    }
    Stack * st = (Stack *) malloc(sizeof(Stack));

    for(i = 0; i < 26; i++) {
        if(alphaCount[i] >0) {
            Elem * elem = (Elem *) malloc(sizeof(Elem));
            elem->ch = i;
            elem->count = alphaCount[i];
            push(st, elem);
        }
    }

    char * res = malloc(sizeof(char) * (len + 1));
    memset(res, '\0', len + 1);
    int count = 0;
    for (i = 0; i < len; i++) {
        if(count == repeatLimit) {
            Elem * large = pop(st);
            if(st->length > 0) {
                Elem * seco = pop(st);
                res[i] = (char) (97 + seco->ch);
                seco->count--;
                if(seco->count != 0) {
                    push(st, seco);
                }
                count = 0;
            } else{
                break;
            }
            push(st, large);
        } else {
            Elem * large = pop(st);
            res[i] = (char) (97 + large->ch);
            large->count--;
            if(large->count > 0){
                push(st, large);
                count++;
            } else{
                count = 0;
            }
        }
    }
    
    return res;
}

int main()
{
    char * s = "ccccccccc";
    int limit = 3;
    char * res = repeatLimitedString(s, limit);
    printf("\n]%s", res);
    s = "aababab";
    limit = 2;
    res = repeatLimitedString(s, limit);
    printf("\n]%s", res);
    s = "cczazcc";
    limit = 3;
    res = repeatLimitedString(s, limit);
    printf("\n]%s", res);
}
