#include <stdio.h>


int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize) {
	int i = 0, j = 0;
	int * rowCount = (int *)malloc(sizeof(int) * matSize);
	for(i = 0; i < matSize; i++) {
		rowCount[i] = *matColSize;
	}
	int * colCount = (int *)malloc(sizeof(int) * (*matColSize));
	for(i = 0; i < *matColSize; i++) {
		colCount[i] = matSize;
	}
	int * rowLabel = (int *) malloc(sizeof(int) * ((*matColSize) * matSize));
	int * colLabel = (int *) malloc(sizeof(int) * (*matColSize * matSize));
	for(i = 0; i < (*matColSize * matSize); i++) {
		rowLabel[i] = 0;
		colLabel[i] = 0;
	}
	for(i = 0; i < matSize; i++) {
		for(j = 0; j < *matColSize; j++) {
			int val = mat[i][j];
			rowLabel[val-1] = i;
			colLabel[val-1] = j;
		}
	}

	for(i = 0; i < arrSize; i++) {
		rowCount[rowLabel[arr[i] - 1]]--;
		colCount[colLabel[arr[i] - 1]]--;
		if(rowCount[rowLabel[arr[i] - 1]] == 0 || colCount[colLabel[arr[i] - 1]] == 0) {
			return i;
		}
	}
	return i - 1;
}
