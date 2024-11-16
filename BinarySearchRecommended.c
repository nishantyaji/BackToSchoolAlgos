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
}
