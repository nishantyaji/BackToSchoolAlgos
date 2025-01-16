int xor(int a, int b) {return a ^ b; }


int reduce(void * fn, int * arr, int * arrSize, int initVal) {
    int (*fun)(int, int) = fn;
    int res = initVal;
    int i = 0;
    for(i = 0; i < *arrSize; i++) {
        res = (* fun)(res, arr[i]);
    }
    return res;
}


int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int (*xorfn)(int, int) = xor;

    int x1 = reduce(xorfn, nums1, &nums1Size, 0);
    int x2 = reduce(xorfn, nums2, &nums2Size, 0);
    return (nums2Size % 2 == 1 ? x1 : 0) ^ (nums1Size % 2 == 1 ? x2 : 0);
}
