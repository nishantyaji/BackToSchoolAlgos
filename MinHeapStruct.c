#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  long long priority;
  int value;
  int index;
} PriorityQueue;

void swap(PriorityQueue * arr, int i, int j) {
    PriorityQueue temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int lchild(int i) {
    return 2 * i + 1;
}

int rchild(int i) {
    return 2 * i + 2;
}

void heapifyNode(PriorityQueue * heap, int * heapSize, int i) {
    if(i >= *heapSize) {
        return;
    }
    int lch = lchild(i);
    int rch = rchild(i);
    
    if(lch >= *heapSize) {
        return;    
    } else if(rch >= *heapSize) {
        if(heap[lch].priority < heap[i].priority) {
            swap(heap, lch, i);
            heapifyNode(heap, heapSize, lch);
        }
    } else{
        if(heap[lch].priority <= heap[rch].priority && heap[lch].priority < heap[i].priority) {
            swap(heap, lch, i);
            heapifyNode(heap, heapSize, lch);
        } else if(heap[rch].priority <= heap[lch].priority && heap[rch].priority < heap[i].priority) {
            swap(heap, rch, i);
            heapifyNode(heap, heapSize, rch);
        }
    }
}

void heapify(PriorityQueue * heap, int * heapSize) {
    int i = 0;
    for(i = *heapSize / 2 - 1; i >= 0; i--) {
        heapifyNode(heap, heapSize, i);
    }
}

void heapPush(PriorityQueue * heap, int * heapSize, PriorityQueue toAdd) {
    bool swapped = true;
    * heapSize = (* heapSize) + 1;
    int idx = *heapSize - 1;
    heap[idx] = toAdd;
    do {
        if(idx == 0 && *heapSize == 1) break; 
        int par = (int) ((idx - 1) / 2);
        idx = par;
        heapifyNode(heap, heapSize, idx);
        if(idx == 0) {
            break;
        }
    }while(swapped == true);
}

PriorityQueue heapPop(PriorityQueue * heap, int * heapSize) {
    PriorityQueue temp = heap[0];
    swap(heap, (*heapSize) - 1, 0);
    * heapSize = * heapSize - 1;
    // It should be heapifyNode and not inefficient heapfify
    heapifyNode(heap, heapSize, 0);
    return temp;
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    long long limit = 201;
    PriorityQueue h[200];
    int i = 0;
    int heapSize = 0;
    for(i = 0; i < numsSize; i++) {
        PriorityQueue pq;
        pq.priority = nums[i] * limit + i;
        pq.value = nums[i];
        pq.index = i;
        heapPush(h, &heapSize, pq);
    }
    
    for(i = 0; i < k; i++) {
        PriorityQueue pq = heapPop(h, &heapSize);
        PriorityQueue pq2;
        pq2.value = pq.value * multiplier;
        pq2.index = pq.index;
        pq2.priority = limit * pq2.value + pq2.index;
        heapPush(h, &heapSize, pq2);
    }
    
    int * res = (int *) malloc(sizeof(int) * numsSize);
    * returnSize = numsSize;
    for(i = 0; i < numsSize; i++) {
        PriorityQueue pq = h[i];
        res[pq.index] = pq.value;
    }
    return res;
}

int main()
{
    printf("Hello World");
    int nums [] = {2,1,3,5,6};
    int retSize = 0;
    int * res = getFinalState(nums, 5, 5, 2, &retSize);
    int i = 0;
    for(i =0; i < retSize; i++) {
        printf("\n%d: %d", i, res[i]);
    }
    return 0;
}
