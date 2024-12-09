/**
* Similar to accumulate in Python or scan in Kotlin
* Check the script ./LeetCode/Problem3152_SpecialArrayII.c for usage
*/

/**
* Still learning C. I will undoubtedly refactor when I learn more about C
*/

#include <stdio.h>
#include <stdbool.h>
int add(int,int);
int add(int a, int b) {
	return a + b;
}

int * accumulate(int * arr, int arrSize, void * fn, bool useInit, int init, int  *retSize) {
	int * res = (int *)malloc(sizeof(int) * arrSize);
	* retSize = arrSize;
	if(fn) {
		int start;
		int i = 0;
		int (*fp)(int, int) = fn;
		if(useInit == true) {
			free(res);
			res = (int *)malloc(sizeof(int) * (arrSize + 1));
			res[0] = init;
			start = 1;
			* retSize = arrSize + 1;
		} else {
			start = 0;
		}
		res[start] = arr[0];
		for(i = start + 1; i <= arrSize; i++) {
			res[i] = fp(res[i-1], arr[i - start]);
		}
	}
	return res;
}

int main()
{
	printf("Hello World");
	int (*fp) (int, int);     // Declaration of a function pointer.
	fp = add;
	int res=(*fp)(1,5);
	printf("%d", res);
	int arr [] = {1,2,3,4,5};
	int accResSize = 0;
	int * accRes = accumulate(arr, 5, fp, false, 0, &accResSize);
	printf("\nResult");
	int i = 0;
	for(i = 0; i < accResSize; i++) {
		printf(" %d", accRes[i]);
	}
	return 0;
}
