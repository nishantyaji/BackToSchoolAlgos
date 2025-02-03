#include <stdio.h>
#include <stdlib.h>

int longestMonotonicSubarray(int* nums, int numsSize) {
	int prev = nums[0], cumu = 1, res = -1, i = 0;

	for(i = 0; i < numsSize; i++) {
		res = abs(cumu) > res ? abs(cumu) : res;
		if(nums[i] > prev) {
			cumu = cumu <= 0 ? 2 : cumu + 1;
		} else if (nums[i] < prev) {
			cumu = cumu >= 0 ? -2 : cumu -1;
		} else {
			cumu = 0;
		}
		prev = nums[i];
	}
	return abs(cumu) > res ? abs(cumu) : res;
}

int main()
{
	int numsSize = 5;
	int * nums = (int *)malloc(sizeof(int) * numsSize);
	nums[0] = 1;
	nums[1] = 4;
	nums[2] = 3;
	nums[3] = 3;
	nums[4] = 2;
	printf("%d", longestMonotonicSubarray(nums, numsSize));
	return 0;
}
