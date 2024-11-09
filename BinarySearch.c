#include <stdio.h>

int binarySearch(int arr[], int n, int searchThis) {
  int mid = 0, start = 0, end = n - 1;

  while (start <= end) {
    mid = (start + end) / 2;
    if (arr[mid] == searchThis) {
      return mid;
    } else if (arr[mid] > searchThis) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return mid;
}

int main() {
  printf("Binary Search. Returns elemenet equal or just greater than it\n");
  int arr[] = {1, 5, 6, 9, 10, 100, 345, 456, 777, 9999};
  int searchThis = 101;
  // scanf("%d", &searchThis);
  int n = sizeof(arr) / sizeof(arr[0]);
  int index = 0;
  index = binarySearch(arr, n, searchThis);
  printf("Index: %d, Value: %d", index, arr[index]);
}