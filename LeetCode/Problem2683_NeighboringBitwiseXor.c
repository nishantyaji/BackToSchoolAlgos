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

bool doesValidArrayExist(int* derived, int derivedSize) {
    int (*xorfn)(int, int) = xor;
    return 0 == reduce(xorfn, derived, &derivedSize, 0);
}
