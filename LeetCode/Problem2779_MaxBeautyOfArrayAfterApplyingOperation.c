#define LIMIT 100002
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

int maximumBeauty(int* nums, int numsSize, int k) {
    if(numsSize == 1) return 1;

    int dp[LIMIT];
    memset(dp, 0, LIMIT * sizeof(int));
    int i = 0;
    for(i = 0; i < numsSize; i++) {
        dp[MAX(0, nums[i] - k)] += 1;
        dp[MIN(100001, nums[i] + k + 1)] -= 1;
    }
    int res = -1, runSum = 0;
    for(i = 0; i < LIMIT; i++) {
        runSum += dp[i];
        res = MAX(res, runSum);
    }
    return res;
}
