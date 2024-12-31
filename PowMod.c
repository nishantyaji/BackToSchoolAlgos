#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <math.h>

int * binaryRepresentation(int num, bool isZeroIndexLSB, int * resSize) {
	int size = floor(log(num) / log(2)) + 1;
	* resSize = size;
	int * res = (int *) malloc(sizeof(int) * size);
	int index = isZeroIndexLSB ? 0: size - 1;

	while(num > 0) {
		int rem = num & 1;
		res[index] = rem;
		index = isZeroIndexLSB ? index + 1: index - 1;
		num = num >> 1;
	}
	return res;
}

long powGeneral(int a, int pw, int base) {
	long long res = 1, num = a;
	int binSize = 0, i = 0;
	int * bin = binaryRepresentation(pw, true, &binSize);
	for(i = 0; i < binSize; i++) {
		if(bin[i] > 0) {
			res = (res * num) % base;
		}
		num = (num * num) % base;
	}
	// free(bin);
	return res;
}

long multiplicativeInverse(int a, int base) {
	return powGeneral(a, base - 2, base);
}

long long powMod(int a, int pw, int base) {
	int num = a;
	if(pw < 0) {
		num = multiplicativeInverse(a, base);
		pw = -pw;
	}
	return powGeneral(num, pw, base);
}

int main()
{
	printf("Hello World");
	printf("\n%lld", powMod(2, 100000, 1000000007));
	printf("\n%lld", powMod(2, -100000, 1000000007));
	return 0;
}
