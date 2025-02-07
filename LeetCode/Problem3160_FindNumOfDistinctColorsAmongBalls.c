#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 50000  // Define the size of the hash table

// Node for linked list (used for handling collisions)
typedef struct Node {
	int key;
	int value;
	struct Node *next;
} Node;

// HashMap structure
typedef struct HashMap {
	Node *buckets[TABLE_SIZE];
} HashMap;

// Hash function (simple modulus-based hash function)
int hash(int key) {
	return key % TABLE_SIZE;
}

// Initialize a new HashMap
HashMap* createHashMap() {
	HashMap* map = (HashMap*)malloc(sizeof(HashMap));
	for (int i = 0; i < TABLE_SIZE; i++) {
		map->buckets[i] = NULL;
	}
	return map;
}

// Insert an element into the hash map
void put(HashMap *map, int key, int value) {
	int index = hash(key);
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	// Check if the key already exists in the map
	Node *current = map->buckets[index];
	while (current != NULL) {
		if (current->key == key) {
		    current->value = value;
			return;
		}
		current = current->next;
	}

	// Insert at the beginning of the linked list
	newNode->next = map->buckets[index];
	map->buckets[index] = newNode;
}

// Search for an element in the hash map
int get(HashMap *map, int key) {
	int index = hash(key);
	Node *current = map->buckets[index];
	while (current != NULL) {
		if (current->key == key) {
			return current->value;
		}
		current = current->next;
	}
	return -1 * TABLE_SIZE;
}

void change(HashMap * mp, HashMap * latest, int limit, int index, int val, int * res) {
    int prevVal = get(latest, index);
	if(prevVal > 0) {
		int temp = get(mp, prevVal);
		put(mp, prevVal,  temp - 1);
		if(temp == 1) {
            int x  = * res;
            * res = x - 1;
		}
	}
	int temp2 = get(mp, val);
	if(temp2 <= -1 * TABLE_SIZE || temp2 == 0) {
        int x = * res;
        * res = x + 1;
        temp2 = 0;
	}
	put(mp, val, temp2 + 1);
	put(latest, index, val);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* queryResults(int limit, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
	HashMap * mp = createHashMap();
	HashMap * latest = createHashMap();
	int * res = (int *) malloc(sizeof(int));
	* res = 0;
	* returnSize = queriesSize;
	int * returnArray = (int *) malloc(sizeof(int) * (queriesSize));
	int i = 0;
	for(i = 0; i < queriesSize; i++) {
		change(mp, latest, limit, queries[i][0], queries[i][1],res);
		returnArray[i] = * res;
	}
	return returnArray;
}
