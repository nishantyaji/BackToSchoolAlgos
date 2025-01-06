#include <stdio.h>
#include <string.h>

int* minOperations(char* boxes, int* returnSize) {
	int sLen = strlen(boxes), i = 0, length = 0;
	for(i = 0; i < sLen; i++) {
		length += boxes[i] == '1' ? 1 : 0;
	}
	int * indices = (int *) malloc(sizeof(int) * length);
	int runIndex = 0;
	for(i = 0; i < sLen; i++) {
		if(boxes[i] == '1') {
			indices[runIndex] = i;
			runIndex++;
		}
	}

	int total = 0;
	for(i = 0; i < length; i++) {
		total += indices[i];
	}
	int * res = (int *) malloc(sizeof(int) * sLen);
	res[0] = total;

	runIndex = 0;
	int right = length;
	if(length > 0 && indices[runIndex] == 0) {
		runIndex++;
		right--;
	}
	for(i = 1; i < sLen; i++) {
		int thisVal = res[i-1];
		int exclude = 0;

		if(runIndex < length && indices[runIndex] == i) {
			runIndex++;
			thisVal--;
			right--;
			exclude = 1;
		}
		thisVal = thisVal - right + (length - right - exclude);
		res[i] = thisVal;
	}
	*returnSize = sLen;
	return res;
}

int main()
{
	char * test = "001011";
	int retSize = 0, i = 0;
	int * res = minOperations(test, &retSize);
	printf("\n");
	for(i = 0; i < retSize; i++) {
		printf(" %d", res[i]);
	}

	return 0;
}
