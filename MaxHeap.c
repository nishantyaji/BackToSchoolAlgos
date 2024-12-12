#include <stdio.h>
#include <stdbool.h>

void swap(int * arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int par(int i){
    return (int)((i - 1) / 2);
}

int lchild(int i) {
    return 2 * i + 1;
}

int rchild(int i) {
    return 2 * i + 2;
}

bool ge(int a, int b) {
    return a > b ? true : false;
}

bool heapifyNode(int * heap, int * heapSize, int i) {
    int lch = lchild(i);
    int rch = rchild(i);
    bool swapped = false;
    if(lch >= *heapSize) {
        return false;    
    } else if(rch >= *heapSize) {
        if(ge(heap[lch], heap[i]) == true) {
            swap(heap, lch, i);
            swapped = true;
        }
    } else{
        if(ge(heap[lch], heap[rch]) == true && ge(heap[lch], heap[i]) ) {
            swap(heap, lch, i);
            swapped = true;
        } else if(ge(heap[rch], heap[lch]) == true && ge(heap[rch], heap[i]) ) {
            swap(heap, rch, i);
            swapped = true;
        }
    }
    return swapped;
}

void heapify(int * heap, int * heapSize) {
    int i = 0;
    int lastNonLeaf =  par((* heapSize) - 1);
    for(i = 0; i <= lastNonLeaf; i++) {
        heapifyNode(heap, heapSize, i);
    }
}

void heapPush(int * heap, int * heapSize, int toAdd) {
    bool swapped = true;
    * heapSize = (* heapSize) + 1;
    int idx = *heapSize - 1;
    heap[idx] = toAdd;
    do {
        idx = par(idx);
        swapped = heapifyNode(heap, heapSize, idx);
        if(idx == 0) break;
    }while(swapped == true);
}

int heapPop(int * heap, int * heapSize) {
    int temp = heap[0];
    swap(heap, *heapSize - 1, 0);
    * heapSize = * heapSize - 1;
    heapify(heap, heapSize);
    return temp;
}

int main()
{
    printf("Hello World");
    int h[1000];
    int heapSize = 0;
    heapPush(h, &heapSize, 1);
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
