#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int startA, int startB, int lenA, int lenB) {
  int *c = (int *)malloc(sizeof(int) *
                         (lenA + lenB)); // initialize all elements to zero
  int aIndex = startA, bIndex = startB, cIndex = 0;
  int i = 0, start = 0;

  while (lenA > aIndex - startA && lenB > bIndex - startB) {
    if (a[aIndex] > a[bIndex]) {
      c[cIndex++] = a[bIndex++];
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
}

void mergeSort(int a[], int m, int n) {
  int temp = 0;
  int mid = (m + n) / 2;
  if (m == n) {
    return;
  } else if (n == m + 1) {
    if (a[m] > a[m + 1]) {
      temp = a[m];
      a[m] = a[m + 1];
      a[m + 1] = temp;
    }
    return;
  }
  mergeSort(a, m, mid);
  mergeSort(a, mid + 1, n);
  merge(a, m, mid + 1, mid + 1 - m, n - mid);
}

void display(int arr[], int numElems) {
  int i = 0;
  for (i = 0; i < numElems; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main() {
  printf("Hi");
  int arr[] = {77, 34, 232, 3, 12};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Before sort: ");
  display(arr, n);
  mergeSort(arr, 0, n - 1);
  printf("After sort: ");
  display(arr, n);
  return 0;
}
