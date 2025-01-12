#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool canBeValid(char* s, char* locked) {
	int n = strlen(s);
	int half = (int) n / 2;
	if(2 * half != n) {
	    return false;
	}
	int opc = 0, clc = 0, i = 0, j = 0;

	for(i = 0; i < n; i++) {
		if(locked[i] == '1') {
			if(s[i] == '(') {
				opc++;
			} else {
				clc++;
			}
			if(opc > half || clc > (int) (i + 1) / 2) {
				return false;
			}
		}
	}
    
    opc = 0;
    clc = 0;
	for(i = n - 1; i >= 0; i--) {
	    j = (int)(n - i) / 2;
		if(locked[i] == '1') {
			if(s[i] == '(') {
				opc++;
			} else {
				clc++;
			}
			if(clc > half || opc > j) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	printf("Hello World");
	char * s1 = "))()))";
	char * locked1 = "010100";
	printf("%d", canBeValid(s1, locked1) ? 1 : 0);

	char * s2 = "()()";
	char * locked2 = "0000";
	printf("%d", canBeValid(s2, locked2) ? 1 : 0);

	char * s3 = ")";
	char * locked3 = "0";
	printf("%d", canBeValid(s3, locked3) ? 1 : 0);

	return 0;
}
