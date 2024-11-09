#include <stdio.h>
#include <stdlib.h>

/**
 * Counts the number of inversions in an array
 2 approaches
 countInversions : Time complexity O(n^2)
 countInversionsUsingMerge: Time complexity O(nlogn)
**/

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

int merge(int a[], int startA, int startB, int lenA, int lenB) {
  int *c = (int *)malloc(sizeof(int) *
                         (lenA + lenB)); // initialize all elements to zero
  int aIndex = startA, bIndex = startB, cIndex = 0;
  int i = 0, start = 0, numInversions = 0;

  while (lenA > aIndex - startA && lenB > bIndex - startB) {
    if (a[aIndex] > a[bIndex]) {
      c[cIndex++] = a[bIndex++];
      numInversions += (lenA - (aIndex - startA));
    } else {
      c[cIndex++] = a[aIndex++];
    }
  }
  while (lenA > aIndex - startA) {
    c[cIndex++] = a[aIndex++];
  }
  while (lenB > bIndex - startB) {
    c[cIndex++] = a[bIndex++];
  }

  start = startA < startB ? startA : startB;
  for (i = 0; i < lenA + lenB; i++) {
    a[start + i] = c[i];
  }
  free(c);
  return numInversions;
}

int countInversionsUsingMerge(int arr[], int s, int e) {
  int temp = 0;
  if (s == e) {
    return 0;
  }
  if (e == s + 1) {
    if (arr[s] > arr[s + 1]) {
      temp = arr[s];
      arr[s] = arr[s + 1];
      arr[s + 1] = temp;
      return 1;
    }
    return 0;
  }
  int mid = (s + e) / 2;
  int left = countInversionsUsingMerge(arr, s, mid);
  int right = countInversionsUsingMerge(arr, mid + 1, e);
  int mergeInv = merge(arr, s, mid + 1, mid + 1 - s, e - mid);
  return left + right + mergeInv;
}

int main() {
  int arr[] = {77, 34, 232, 3, 12};
  //   int arr[] = {2,3,8,6,1};
  //   int arr[] = {2, 3, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  //   int ans = countInversions(arr, n);
  int ans = countInversionsUsingMerge(arr, 0, n - 1);
  printf("\nNumber of Inversions: %d", ans);
  return 0;
}