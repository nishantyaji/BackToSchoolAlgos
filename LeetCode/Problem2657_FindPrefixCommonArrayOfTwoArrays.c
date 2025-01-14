#include <stdio.h>

int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
	int * aset = (int *) malloc(sizeof(int) * (ASize + 1));
	int * bset = (int *) malloc(sizeof(int) * (BSize + 1));
	int i = 0;
	for(i = 0; i <= ASize; i++) {
		aset[i] = 0;
		bset[i] = 0;
	}

	*returnSize = ASize;
	int * res = (int *) malloc(sizeof(int) * ASize);
	res[ASize-1] = ASize;

	for(i = ASize - 1; i > 0; i--) {
		if(aset[B[i]] > 0 && bset[A[i]] > 0) {
			res[i-1] = res[i];
		} else if(B[i] == A[i] || aset[B[i]] > 0 || bset[A[i]] > 0) {
			res[i-1] = res[i] - 1;
		} else {
			res[i-1] = res[i] - 2;
		}
		aset[A[i]] = 1;
		bset[B[i]] = 1;
	}
	return res;
}

int main()
{
	int a[] = {1,3,2,4};
	int b[] = {3,1,2,4};
	int returnSize = 0, i = 0;
	int * res = findThePrefixCommonArray(a, 4, b, 4, &returnSize);
	for(i = 0; i < returnSize; i++) {
		printf("\n%d", res[i]);
	}
	return 0;
}
