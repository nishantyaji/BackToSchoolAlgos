#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigit(char c) {
	int aInt = (int) '0';
	int cInt = (int) c;
	return cInt >= aInt && cInt - aInt <= 9 ? 1 : 0;
}

char* clearDigits(char* s) {
	int i = 0, end = 0;
	int n = strlen(s);
	char * res = (char *) malloc(sizeof(char) * (n +1));
	for(i = 0; i < n + 1; i++) {
		res[i] = 0;
	}

	for(i = 0; i < n; i++) {
		if(isDigit(s[i])) {
			if(end > 0) {
				end--;
				res[end] = 0;
			}
		} else {
			res[end] = s[i];
			end++;
		}
	}
	return res;
}


int main()
{
	printf("\n%s", clearDigits("abc"));
	printf("\n%s", clearDigits("cb34"));
	return 0;
}
