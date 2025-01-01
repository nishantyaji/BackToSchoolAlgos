#include <stdio.h>

int maxScore(char* s) {
	int res = -501, zeroes = 0, ones = 0, i = 0;

	for(i = 0; i < strlen(s); i++) {
		if(s[i] == '0') {
			zeroes++;
		} else {
			ones++;
		}
		if(i < strlen(s) - 1) {
			res = res > (zeroes - ones) ? res : zeroes - ones;
		}
	}
	return res + ones;
}

int main()
{
	printf("Hello World");
	char s1[] = "011101";
	printf("\n%d", maxScore(s1));
	char s2[] = "00111";
	printf("\n%d", maxScore(s2));
	char s3[] = "1111";
	printf("\n%d", maxScore(s3));

	return 0;
}
