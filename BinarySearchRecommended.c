#include <stdio.h>

int binarySearchLeft(int arr[], int n, int searchThis) {
  int mid = 0, start = 0, end = n - 1;

  while (start <= end) {
    mid = (start + end) / 2;
    if (arr[mid] < searchThis) {
      start = mid + 1;
    } else {
        end = mid - 1;
    }
  }
  return start;
}


int binarySearchRight(int arr[], int n, int searchThis) {
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

int * insort(int arr[], int n, int insertThis) {
    int idx = binarySearchRight(arr, n, insertThis);
    int * newArr = (int *) malloc(sizeof(int) * (n+1));
    int i = 0;
    for(i = 0; i < idx; i++) {
        newArr[i] = arr[i];
    }
    newArr[idx] = insertThis;
    for(i = idx; i < n; i++) {
        newArr[i+1] = arr[i];
    }
    return newArr;
}

void display(int * arr, int n) {
    int i = 0;
    printf("\n");
    for(i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}


int main() {
  printf("Binary Search.\n");
  int arr[] = {1, 1, 5, 5, 5, 6, 6, 9, 10, 10,10,10,10,11, 100, 345, 456, 777, 9999, 9999, 9999};
  
  int n = sizeof(arr) / sizeof(arr[0]);
  int index = 0;
  int searchThis = 5;
  index = binarySearchLeft(arr, n, searchThis);
  printf("\nBSLEFT Index: %d, Value: %d", index, arr[index]);
  index = binarySearchRight(arr, n, searchThis);
  printf("\nBSRIGHT Index: %d, Value: %d", index, arr[index]);
  searchThis = 9999;
  index = binarySearchLeft(arr, n, searchThis);
  printf("\nBSLEFT Index: %d, Value: %d", index, arr[index]);
  index = binarySearchRight(arr, n, searchThis);
  printf("\nBSRIGHT Index: %d, Value: %d", index, arr[index]);
  searchThis = 1;
  index = binarySearchLeft(arr, n, searchThis);
  printf("\nBSLEFT Index: %d, Value: %d", index, arr[index]);
  index = binarySearchRight(arr, n, searchThis);
  printf("\nBSRIGHT Index: %d, Value: %d", index, arr[index]);
  searchThis = 2;
  index = binarySearchLeft(arr, n, searchThis);
  printf("\nBSLEFT Index: %d, Value: %d", index, arr[index]);
  index = binarySearchRight(arr, n, searchThis);
  printf("\nBSRIGHT Index: %d, Value: %d", index, arr[index]);
  
  int * newArr = insort(arr, n, 7); 
  display(newArr, n + 1);
}
