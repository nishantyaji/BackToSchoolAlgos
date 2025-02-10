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

long long countBadPairs(int* nums, int numsSize) {
	HashMap * d = createHashMap();
	int i = 0, val = 1;
	long long res = 0;
	for(i = 0; i < numsSize; i++) {
		int temp = nums[i] - i;
		int tempGet = get(d, temp);
		val = 1;
		if(tempGet > -1) {
			val = tempGet + 1;
		}
		put(d, temp, val);
	}


	for (i = 0; i < TABLE_SIZE; i++) {
		Node *current = d->buckets[i];
		while (current != NULL) {
			long long temp = current->value;
			if(temp >= 1) {
				res += ((numsSize - temp) * temp);
			}
			current = current->next;
		}
	}
	return (long long) res /2;
}

int main()
{
	int sz = 9;
	int * test = (int *) malloc(sizeof(int) * sz);
	test[0] = 28;
	test[1] = 22;
	test[2] = 74;
	test[3] = 57;
	test[4] = 47;
	test[5] = 76;
	test[6] = 2;
	test[7] = 93;
	test[8] = 6;
	printf("\n\n%lld", countBadPairs(test, sz));
	return 0;
}
