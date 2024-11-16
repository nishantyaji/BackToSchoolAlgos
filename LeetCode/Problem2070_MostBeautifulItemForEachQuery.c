typedef struct {
  int price;
  int beauty;
} Pair;

int compare(const void *a, const void *b) {
  Pair *first = (Pair *)a;
  Pair *second = (Pair *)b;

  if (first->price != second->price) {
    return first->price - second->price;
  }
  return first->beauty - second->beauty;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maximumBeauty(int **items, int itemsSize, int *itemsColSize, int *queries,
                   int queriesSize, int *returnSize) {
  int *res = (int *)malloc(sizeof(int) * queriesSize);
  *returnSize = queriesSize;

  Pair *arr = (Pair *)malloc(sizeof(Pair) * (itemsSize + queriesSize));
  int numPairs = itemsSize + queriesSize;

  int i = 0;
  for (i = 0; i < itemsSize; i++) {
    Pair *thisPair = &arr[i];
    thisPair->price = items[i][0];
    thisPair->beauty = items[i][1];
  }
  int j = 0;
  for (j = 0; j < queriesSize; j++) {
    Pair *thisPair = &arr[i + j];
    thisPair->price = queries[j] + 1;
    thisPair->beauty = -(j + 1);
  }
  qsort(arr, numPairs, sizeof(Pair), compare);
  i = 0;
  int thisMax = 0;
  for (i = 0; i < numPairs; i++) {
    Pair *thisPair = &arr[i];
    if (thisPair->beauty < 0) {
      res[-(thisPair->beauty + 1)] = thisMax;
    } else {
      thisMax = thisMax > thisPair->beauty ? thisMax : thisPair->beauty;
    }
  }
  return res;
}