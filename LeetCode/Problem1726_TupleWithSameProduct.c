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

int tupleSameProduct(int* nums, int numsSize) {
    HashMap*  map = createHashMap();
    int i = 0, j =0, prod = 0;
	for(i = 0; i < numsSize; i++) {
		for(j = i + 1; j < numsSize; j++) {
			prod = nums[i] * nums[j];
			int val = get(map, prod);
			if(val >= 0) {
			    put(map, prod, val + 1);
			} else {
				put(map, prod, 1);
			}
		}
	}
	int res = 0;
	
	for (i = 0; i < TABLE_SIZE; i++) {
		Node *current = map->buckets[i];
		while (current != NULL) {
		    int temp = current->value;
		    if(temp > 1) {
		        printf("\n%d %d", current->key, temp);
		        res += (4 * temp * (temp - 1));       
		    }
			current = current->next;
		}
	}
	return res;
    
}

int main()
{
    printf("Hello World");
    int * nums = (int *)malloc(sizeof(int) * 5);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 4;
    nums[3] = 5;
    nums[4] = 10;
    printf("\n %d", tupleSameProduct(nums, 5));

    return 0;
}
