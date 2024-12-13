#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(long long * arr, int i, int j) {
    long long temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int lchild(int i) {
    return 2 * i + 1;
}

int rchild(int i) {
    return 2 * i + 2;
}

void heapifyNode(long long * heap, int * heapSize, int i) {
    if(i >= *heapSize) {
        return;
    }
    long long lch = lchild(i);
    long long rch = rchild(i);
    
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

void heapify(long long * heap, int * heapSize) {
    int i = 0;
    for(i = *heapSize / 2 - 1; i >= 0; i--) {
        heapifyNode(heap, heapSize, i);
    }
}

void heapPush(long long * heap, int * heapSize, long long toAdd) {
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

long long heapPop(long long * heap, int * heapSize) {
    long long temp = heap[0];
    swap(heap, (*heapSize) - 1, 0);
    * heapSize = * heapSize - 1;
    heapifyNode(heap, heapSize, 0); 
    // This should be heapifyNode and not heapify 
    return temp;
}


long long findScore(int* nums, int numsSize) {
    bool flags[numsSize];
    memset(flags, 0, numsSize); 
    long long h[2 * numsSize];
    int heapSize = 0;
    int i = 0;
    long long mult = 1000001;
    for(i = 0; i < numsSize; i++) {
        long long longi = (long long) (i);
        long long toAdd = mult * nums[i] + longi;
        heapPush(h, &heapSize, toAdd);    
    }
    
    int count = 0;
    long long res = 0;
    int loop = 0;
    while(count < numsSize && heapSize > 0) {
        loop++;
        if(count % 100 == 0) printf("\n%d .. %d .. %d", count, heapSize, loop);
        
        long long temp = heapPop(h, &heapSize);
        long long n =  (temp / mult);
        long long i =  (temp % mult);
        if(flags[i] == false) {
            res += n;
            flags[i] = true;
            count++;
        
            if(i - 1 >= 0 && flags[i - 1] == false) {
                flags[i-1] = true;
                count++;
            }
            if(i + 1 < numsSize && flags[i + 1] == false) {
                flags[i + 1] = true;
                count++;
            }
        }
    }

    return res;
}
