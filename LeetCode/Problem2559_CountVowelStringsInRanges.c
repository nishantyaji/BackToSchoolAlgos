#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int isVowelChar(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
}

int isVowel(char * s) {
    return isVowelChar(s[0]) && isVowelChar(s[strlen(s) - 1]);
}

int * map(void * fn, char ** arr, int * arrSize) {
	int (*fun)(char *) = fn;
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
	int retSize = 0, i = 0;
	int * acc = accumulate(mapRes, wordsSize, add, true, 0, &retSize);
	* returnSize = queriesSize;
	int * res = (int *) malloc(sizeof(int) * queriesSize);
	for(i = 0; i < queriesSize; i++) {
		res[i] = acc[queries[i][1] + 1] - acc[queries[i][0]];
	}
	return res;
}

int * * getQueries() {
	int * * queries = (int **)malloc(sizeof(int *) * 3);
	int i = 3;
	for( i = 0; i < 3; i++) {
		queries[i] = (int *) malloc(sizeof(int) * 2);
	}
	queries[0][0] = 0;
	queries[0][1] = 2;
	queries[1][0] = 1;
	queries[1][1] = 4;
	queries[2][0] = 1;
	queries[2][1] = 1;
	return queries;
}

char ** getTestString() {
	char ** s = (char **)malloc(sizeof(char *) * 5);
	int i = 0;
	for(i = 0; i < 5; i++) {
		char * temp = (char *) malloc(sizeof(char) * 40);
		memset(temp, 0, sizeof(char) * 40);
		s[i] = temp;
	}
	s[0][0] = 'a';
	s[0][0] = 'b';
	s[0][0] = 'a';

	s[0][0] = 'b';
	s[0][0] = 'c';
	s[0][0] = 'b';

	s[0][0] = 'e';
	s[0][0] = 'c';
	s[0][0] = 'e';

	s[0][0] = 'a';
	s[0][0] = 'a';

	s[0][0] = 'e';
}

int main()
{
	printf("Hello World");
	char *test[] = {"aba","bcb","ece","aa","e"};
	int ** queries = getQueries();
	int resSize = 0, i = 0, queriesColSize = 2;
	int * res = vowelStrings(test, 5, queries, 3, &queriesColSize, &resSize);
	printf("\n");
	for(i = 0; i < resSize; i++) {
		printf(" %d", res[i]);
	}
	return 0;
}
