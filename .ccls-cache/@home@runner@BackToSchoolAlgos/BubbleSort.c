#include <stdio.h>

void swap(int arr[], int index1, int index2) {
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

void bubbleSort(int arr[], int n){
  int i = 0, j = 0;
  for(i = 0; i < n - 1; i++) {
    for(j = 0; j  < n - i - 1; j++) {
      if(arr[j] > arr[j + 1]){
        swap(arr, j, j+1);
      }
    }
  }
}

void display(int arr[], int n) {
  int i = 0;
  for(i = 0; i < n; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}


int main(void) {
  int arr[] = {77, 34, 232, 3, 12};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Before Sort: ");
  display(arr, n);
  bubbleSort(arr, n);
  printf("After Sort: ");
  display(arr, n);
  return 0;
}