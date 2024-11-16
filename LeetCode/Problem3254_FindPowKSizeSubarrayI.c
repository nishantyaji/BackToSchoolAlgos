/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    if(k == 1){
        *returnSize = numsSize;
        return nums;
    }
    int *diffs = (int *) malloc(sizeof(int) * (numsSize-1));
    int * res = (int *) malloc(sizeof(int) * (numsSize- k + 1));
    int count = 0, i = 0;
    *returnSize = numsSize - k + 1;
    for(i = 1; i < numsSize; i++) {
        if(i <= numsSize - k + 1) {
            res[i-1] = -1;
        }
        diffs[i-1] = nums[i] - nums[i-1];
    }
    i = 0;
    while(i < numsSize-1) {
        if(diffs[i] == 1) {
            count++;
        } else{
            count = 0;
        }
        
        if(count == k-1) {
            res[i+1-k+1] = nums[i -(k-2)] + k - 1;
            count--;
        }
        i++;
    }
    return res;
}