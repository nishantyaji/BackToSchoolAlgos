#include <stdio.h>
#include <stdbool.h>

bool is_even(int);
bool is_even(int a) {
	return a % 2 == 0;
}

int * filter(int * arr, int arrSize, void * filterFn, int * retSize) {
	bool (*fn)(int) = filterFn;
	int count = 0;
	int i = 0;
	for(i = 0; i < arrSize; i++) {
		if(fn(arr[i]) == true) {
			count++;
		}
	}
	* retSize = count;
	int * res = (int *) malloc(sizeof(int) * count);
	int idx = 0;
	for(i = 0; i < arrSize; i++) {
		if(fn(arr[i]) == true) {
			res[idx] = arr[i];
			idx++;
		}
	}
	return res;
}

int main()
{
	printf("Hello World");

	int (*fp) (int);     // Declaration of a function pointer.
	fp = is_even;
	int arr [] = {1,2,3,4,5};
	int resSize = 0;
	int * accRes = filter(arr, 5, fp, &resSize);
	printf("\nResult");
	int i = 0;
	for(i = 0; i < resSize; i++) {
		printf(" %d", accRes[i]);
	}

	return 0;
}
