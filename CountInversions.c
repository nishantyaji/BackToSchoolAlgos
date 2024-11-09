#include <stdio.h>

int countInversions(int arr[], int n) {
  int i = 0, j = 0, numInversions = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        printf("\n%d (arr[%d]) > %d (arr[%d])", arr[i], i, arr[j], j);
        numInversions++;
      }
    }
  }
  return numInversions;
}

int main() {
  // int arr[] = {77, 34, 232, 3, 12};
  int arr[] = {2, 3, 8, 6, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int ans = countInversions(arr, n);
  printf("\nNumber of Inversions: %d", ans);
  return 0;
}