#include <stdio.h>
#include <stdlib.h>

/**
*  For example refer: LeetCode/Problem2415_ReverseOddLevelsOfBinTree.c
*/

typedef struct Elem {
	int value;
	struct Elem * prev;
	struct Elem * next;
} Elem;

typedef struct Deque {
	int length;
	struct Elem * head;
	struct Elem * end;
} Deque;

Elem* getElem(int val) {
	Elem * elem = (Elem *) malloc(sizeof(Elem));
	elem->value = val;
	elem->prev = NULL;
	elem->next = NULL;
	return elem;
}

void push(Deque * dq, Elem * elem) {
	if(dq->length == 0) {
		dq->head = elem;
	} else {
		elem->prev = dq->end;
		dq->end->next = elem;
	}
	elem->next = NULL;
	dq->end = elem;
	dq->length = dq->length + 1;
}

Elem * pop(Deque * dq) {
	Elem * elem = getElem(dq->end->value);
	if(dq->end->prev != NULL)
		dq->end = dq->end->prev;
	dq->end->next = NULL;
	dq->length = dq->length - 1;
	return elem;
}

Elem * popLeft(Deque * dq) {
	Elem * elem = getElem(dq->head->value);
	if(dq->head->next != NULL)
		dq->head = dq->head->next;
	dq->head->prev = NULL;
	dq->length = dq->length - 1;
	return elem;
}
