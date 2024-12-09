/**
* Similar to accumulate in Python or scan in Kotlin
* Check the script ./LeetCode/Problem3152_SpecialArrayII.c for usage
*/

/**
* Still learning C. I will undoubtedly refactor when I learn more about C
*/


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
