#include <stdio.h>

int countGoodStrings(int low, int high, int zero, int one) {
	int min = zero > one ? one : zero;
	int max = zero < one ? one : zero;
	int base = 1000000007;
	int * dp = (int *)malloc(sizeof(int) * (max + high + 1));
	int i = 0;
	for(i = 0; i <= high + max; i++) {
		dp[i] = 0;
	}

	dp[min] += 1;
	dp[max] += 1;
	for(i = min; i <= high; i++) {
		if(dp[i] > 0) {
			dp[i+zero] = (dp[i+zero] + dp[i]) % base;
			dp[i+one] = (dp[i+one] + dp[i]) % base;
		}
	}

	int res = 0;
	for(i = low; i <= high; i++) {
		res = (res + dp[i]) % base;
	}
	return res;
}
