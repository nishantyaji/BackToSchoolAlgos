#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int add(int,int);  
int add(int a, int b){
    return a + b;
}
int * accumulate(int * arr, int arrSize, void * fn, bool useInit, int init, int  *retSize) {
    int * res = (int *)malloc(sizeof(int) * arrSize);
    * retSize = arrSize;
    if(fn) {
        int start; 
        int i = 0;
        int (*fp)(int, int) = fn;
        if(useInit == true) {
            free(res);
            res = (int *)malloc(sizeof(int) * (arrSize + 1));
            res[0] = init;
            start = 1;
            * retSize = arrSize + 1;
        } else {
            res = (int *)malloc(sizeof(int) * arrSize);
            start = 0;
        }
        res[start] = arr[0];
        for(i = start + 1; i <= arrSize - 1 + start; i++) {
            res[i] = fp(res[i-1], arr[i - start]);
        }
    }
    return res;
}

bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {

    int * flags = (int *) malloc(sizeof(int) * numsSize);
    flags[0] = 0;
    int i = 0;
    for(i = 1; i < numsSize; i++) {
        int sm = (nums[i] + nums[i-1]) % 2;
        flags[i] = (sm == 0? 1: 0);
    }
    int prefixSize = 0;
    int * prefix = accumulate(flags, numsSize, add, false, 0, &prefixSize);
    bool * res = (bool *) malloc(sizeof(bool) * queriesSize);
    for(i = 0; i < queriesSize; i++) {
        res[i] = prefix[queries[i][1]] - prefix[queries[i][0]] == 0 ? true: false;
    }
    * returnSize = queriesSize;
    return res;
}
