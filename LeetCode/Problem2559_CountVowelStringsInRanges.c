#include <stdio.h>
#include <stdbool.h>

int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
}

int * map(void * fn, char ** arr, int * arrSize) {
    int * (*fun)(char) = fn;
    int * res = (int *) malloc(sizeof(int) * (*arrSize));
    int i = 0;
    for(i = 0; i < *arrSize; i++) {
        res[i] = (*fun)(arr[i]);
    }
    return res;
}

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

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int * mapRes = map(isVowel, words, &wordsSize);
    int retSize = 0, i == 0;
    int * acc = accumulate(mapRes, wordsSize, add, true, 0, retSize);
    * returnSize = queriesSize;
    for(i = 0; i < queriesSize; i++) {
        returnSize[i] = acc[queries[i][1] + 1] - acc[queries[i][0]];
    }
}

int main()
{
    printf("Hello World");

    return 0;
}
