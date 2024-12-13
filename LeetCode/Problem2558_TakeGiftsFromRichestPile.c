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

bool ge(int a, int b) {
    // Remember that this always has to be greater than equal to
    // and not equal to
    // becaues the proper blocks in the heapifyNode method are not called
    // Example parent = 2 (left child = 8) (right child = 8)
    return a >= b;
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
        if(ge(heap[lch], heap[i]) == true) {
            swap(heap, lch, i);
            heapifyNode(heap, heapSize, lch);
    
        }
    } else{
        if(ge(heap[lch], heap[rch]) == true && ge(heap[lch], heap[i]) == true) {
            swap(heap, lch, i);
            heapifyNode(heap, heapSize, lch);
    
        } else if(ge(heap[rch], heap[lch]) == true && ge(heap[rch], heap[i]) == true ) {
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
    // The following should be heapifyNode and not heapify
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


long long pickGifts(int* gifts, int giftsSize, int k) {
    int h[2000];
    long long res = 0;
    int i = 0, heapSize = 0;
    for(i = 0; i < giftsSize; i++) {
        heapPush(h, &heapSize, gifts[i]);
    }
   
    for(i = 0; i < k; i++) {
        int temp = heapPop(h, &heapSize);
        int sq = (int) sqrt(temp);
        heapPush(h, &heapSize, sq);
    }
    while(heapSize > 0) {
        int temp = heapPop(h, &heapSize);
        res += temp;

    }
    return res;
}

int main()
{
    int gifts [23] ={ 56,41,27,71,62,57,67,34,8,71,2,12,52,1,64,43,32,42,9,25,73,29,31};
    long long res = pickGifts(gifts,  23,52);
    printf("\n\%lld", res );
}
