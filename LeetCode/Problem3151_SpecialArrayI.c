#include <stdio.h>
#include <stdbool.h>

bool isArraySpecial(int* nums, int numsSize) {
    int i = 0;
    for(i = 0; i < numsSize - 1; i++) {
        if((nums[i] + nums[i + 1]) % 2 == 0) {
            return false;
        }
    }
    return true;
}
