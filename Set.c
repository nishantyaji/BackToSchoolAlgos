/******************************************************************************

                            Online C Debugger.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Debug" button to debug program.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 10  // Define the size of the hash table

// Node for linked list (used for handling collisions)
typedef struct Node {
	int data;
	struct Node *next;
} Node;

// HashSet structure
typedef struct HashSet {
	Node *buckets[TABLE_SIZE];
} HashSet;

// Hash function (simple modulus-based hash function)
int hash(int key) {
	return key % TABLE_SIZE;
}

// Initialize a new HashSet
HashSet* createHashSet() {
	HashSet* set = (HashSet*)malloc(sizeof(HashSet));
	for (int i = 0; i < TABLE_SIZE; i++) {
		set->buckets[i] = NULL;
	}
	return set;
}

// Insert an element into the hash set
void insert(HashSet *set, int key) {
	int index = hash(key);
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = key;
	newNode->next = NULL;

	// Check if the key already exists in the set
	Node *current = set->buckets[index];
	while (current != NULL) {
		if (current->data == key) {
			free(newNode);  // Avoid adding duplicates
			return;
		}
		current = current->next;
	}

	// Insert at the beginning of the linked list
	newNode->next = set->buckets[index];
	set->buckets[index] = newNode;
}

// Search for an element in the hash set
bool search(HashSet *set, int key) {
	int index = hash(key);
	Node *current = set->buckets[index];
	while (current != NULL) {
		if (current->data == key) {
			return true;
		}
		current = current->next;
	}
	return false;
}

// Remove an element from the hash set
void removeElement(HashSet *set, int key) {
	int index = hash(key);
	Node *current = set->buckets[index];
	Node *prev = NULL;

	// Find the node to remove
	while (current != NULL) {
		if (current->data == key) {
			if (prev == NULL) {
				// Remove the first element
				set->buckets[index] = current->next;
			} else {
				// Remove from middle or end of the list
				prev->next = current->next;
			}
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
}

// Print the hash set for debugging
void printHashSet(HashSet *set) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		printf("Bucket %d: ", i);
		Node *current = set->buckets[i];
		while (current != NULL) {
			printf("%d -> ", current->data);
			current = current->next;
		}
		printf("NULL\n");
	}
}

// Free the memory used by the hash set
void freeHashSet(HashSet *set) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		Node *current = set->buckets[i];
		while (current != NULL) {
			Node *temp = current;
			current = current->next;
			free(temp);
		}
	}
	free(set);
}

int main() {
	HashSet *set = createHashSet();

	insert(set, 5);
	insert(set, 15);
	insert(set, 25);
	insert(set, 35);

	printf("HashSet after inserts:\n");
	printHashSet(set);

	printf("Searching for 15: %s\n", search(set, 15) ? "Found" : "Not found");
	printf("Searching for 100: %s\n", search(set, 100) ? "Found" : "Not found");

	removeElement(set, 15);
	printf("HashSet after removing 15:\n");
	printHashSet(set);

	freeHashSet(set);

	return 0;
}
