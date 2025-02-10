#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 1000000  // Define the size of the hash table

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
	return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
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
	return -1;
}

// Remove an element from the hash Map
void removeElement(HashMap *map, int key) {
	int index = hash(key);
	Node *current = map->buckets[index];
	Node *prev = NULL;

	// Find the node to remove
	while (current != NULL) {
		if (current->key == key) {
			if (prev == NULL) {
				// Remove the first element
				map->buckets[index] = current->next;
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

// Print the hash map for debugging
void printHashMap(HashMap *map) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		printf("Bucket %d: ", i);
		Node *current = map->buckets[i];
		while (current != NULL) {
			printf("%d -> ", current->key);
			current = current->next;
		}
		printf("NULL\n");
	}
}

// Free the memory used by the hash map
void freeHashMap(HashMap *map) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		Node *current = map->buckets[i];
		while (current != NULL) {
			Node *temp = current;
			current = current->next;
			free(temp);
		}
	}
	free(map);
}
// For implementation check Problem 1726
