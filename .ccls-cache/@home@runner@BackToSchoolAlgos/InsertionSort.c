#include <stdio.h>

void insertionSort(int arr[], int n) {
  int i = 0, j = 0, key = 0;
  for (j = 1; j < n; j++) {
    key = arr[j];
    i = j - 1;
    while (i >= 0 && arr[i] > key) {
      arr[i + 1] = arr[i];
      i--;
    }
    arr[i + 1] = key;
  }
}

void display(int arr[], int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {77, 34, 232, 3, 12};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Before Sort: ");
  display(arr, n);
  insertionSort(arr, n);
  printf("After Sort: ");
  display(arr, n);
  return 0;
}