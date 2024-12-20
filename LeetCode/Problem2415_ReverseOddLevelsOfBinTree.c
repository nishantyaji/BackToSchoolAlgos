#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


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


void recurse(struct TreeNode * root, Deque * mp, int depth) {
	Deque *dq = &mp[depth];
	push(dq, getElem(root->val));
	if(root->left != NULL) {
		recurse(root->left, mp, depth+1);
	}
	if(root->right != NULL) {
		recurse(root->right, mp, depth+1);
	}
}

void assign(struct TreeNode * root, Deque * mp, int depth) {
	Deque * dq = &mp[depth];
	Elem * elem = NULL;
	if(depth % 2 == 1) {
		elem = pop(dq);
	} else {
		elem = popLeft(dq);
	}

	root->val = elem->value;
	if(root->left != NULL) {
		assign(root->left, mp, depth+1);
	}
	if(root->right != NULL) {
		assign(root->right, mp, depth+1);
	}
}


struct TreeNode* reverseOddLevels(struct TreeNode* root) {
	Deque * mp = (Deque *)malloc(sizeof(Deque) * 100);
	memset(mp, 0, sizeof(Deque) * 100);

	int i = 0;
	for(i = 0; i < 100; i++) {
		mp[i].head = NULL;
		mp[i].end = NULL;
		mp[i].length = 0;
	}

	if(root != NULL) {
		recurse(root, mp, 0);
		assign(root, mp, 0);
	}

	return root;
}
