#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    int * first = (int *) a;
    int * second = (int *) b;
    return *first - *second;
}

int binarySearchRight(int * arr, int n, int searchThis) {
  int mid = 0, start = 0, end = n - 1;

  while (start <= end) {
    mid = (start + end) / 2;
    if (arr[mid] > searchThis) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return start;
}

bool checkIfExist(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);
    int numZeros = 0;
    int i = 0;
    for(i = 0; i < arrSize; i++) {
        if(arr[i] == 0) {
            numZeros++;
        }
    }
    for(i = 0; i < arrSize - 1; i++) {
        int toFind = 2 * arr[i];
        if(arr[i] != 0) {
            int idx = binarySearchRight(arr, arrSize, toFind);
            if(idx > 0 && arr[idx-1] == toFind) 
                return true;
        }
    }
 
    return numZeros >= 2 || false;
}
