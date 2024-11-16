int compare(const void *a, const void *b) {
    int * first = (int *) a;
    int * second = (int *) b;
    return *first - *second;
}

int binarySearch(int* arr, int n, int searchThis){
	int mid = 0, start = 0, end = n-1;

	while(start <= end) {
		mid = (start + end) / 2;
		if(arr[mid] >= searchThis) {
			end = mid - 1;  
		} else{
			start = mid + 1;
		}
	}
	return start;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), compare);
    if(numsSize < 2 || (nums[numsSize-2] + nums[numsSize-1] < lower) || (nums[0] + nums[1] > upper)) {
        return 0;
    }    
    long long res = 0;
    int i = 0;
    for(i = 0; i < numsSize; i++) {
        int lIdx = binarySearch(nums, numsSize, lower - nums[i]);
        int uIdx = binarySearch(nums, numsSize, upper + 1 - nums[i]);
        if(uIdx > lIdx) {
            res += (uIdx - lIdx);
            printf("%d : %d %d", i, lIdx, uIdx);
            if(lIdx <= i && i < uIdx) {
                res--;
            }
        }
    }
    return res / 2;

}