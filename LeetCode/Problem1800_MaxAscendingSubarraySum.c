#include <stdio.h>

int maxAscendingSum(int* nums, int numsSize) {
    int i = 0, cumu = 0, prev = -1, res = -1;
    
    for(i = 0; i < numsSize; i++) {
        res = res > cumu ? res : cumu;
        cumu = nums[i] > prev ? cumu + nums[i] : nums[i];
		prev = nums[i];
    }    
	return res > cumu ? res : cumu;
}
