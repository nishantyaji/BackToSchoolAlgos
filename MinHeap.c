#include <stdio.h>
#include <stdbool.h>
#include <math.h>


void swap(int * arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int lchild(int i) {
    return 2 * i + 1;
}

int rchild(int i) {
    return 2 * i + 2;
}

void heapifyNode(int * heap, int * heapSize, int i) {
    if(i >= *heapSize) {
        return;
    }
    int lch = lchild(i);
    int rch = rchild(i);
    
    if(lch >= *heapSize) {
        return;    
    } else if(rch >= *heapSize) {
        if(heap[lch] < heap[i]) {
            swap(heap, lch, i);
            heapifyNode(heap, heapSize, lch);
        }
    } else{
        if(heap[lch] <= heap[rch] && heap[lch] < heap[i]) {
            swap(heap, lch, i);
            heapifyNode(heap, heapSize, lch);
        } else if(heap[rch] <= heap[lch] && heap[rch] < heap[i]) {
            swap(heap, rch, i);
            heapifyNode(heap, heapSize, rch);
        }
    }
}

void heapify(int * heap, int * heapSize) {
    int i = 0;
    for(i = *heapSize / 2 - 1; i >= 0; i--) {
        heapifyNode(heap, heapSize, i);
    }
}

void heapPush(int * heap, int * heapSize, int toAdd) {
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

int heapPop(int * heap, int * heapSize) {
    int temp = heap[0];
    swap(heap, (*heapSize) - 1, 0);
    * heapSize = * heapSize - 1;
    // It should be heapifyNode and not inefficient heapfify
    heapifyNode(heap, heapSize, 0);
    return temp;
}

void displayHeap(int * heap, int * heapSize) {
    int depth = 1+ ((int)(log2(*heapSize)));
    int idx = 0,  i = 0, ended = 0;
    for(i = 0; i < depth; i++) {
        for(; idx < (1 << (i+1)) - 1; idx++) {
            if(idx == * heapSize) {
                ended = 1;
                break;
            }
            int j = 0;
            for(j = 2 * i; j < 2 * depth; j++) {
                printf(" ");
            }
            printf("%d", heap[idx]);          
        }
        if(ended == 1) {
            break;
        }
        printf("\n");
    }
    printf("\n\n");
}


int main()
{
    printf("Hello World");
    int h[1000];
    int heapSize = 0;
    heapPush(h, &heapSize, 11);
    heapPush(h, &heapSize, 2);
    heapPush(h, &heapSize, 5);
    int i = 0;
    for(i = 0; i < heapSize; i++){
        printf("\n%d", h[i]);
    }
    while(heapSize > 0) {
        int temp = heapPop(h, &heapSize);
        printf("\nDeleted %d", temp);
    }
    return 0;
}
