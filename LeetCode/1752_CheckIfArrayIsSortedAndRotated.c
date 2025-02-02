bool check(int* nums, int numsSize) {
    int first = 0, i = 0, j = 0;

    for(i = 0; i < numsSize; i++) {
        if(nums[(i - 1 + numsSize) % numsSize] > nums[i]){
            first = i;
            break;
        }
    }

    int * arr = (int *) malloc(sizeof(int) * (2 * numsSize));
    for(i = 0; i < 2; i++) {
        for(j = 0; j < numsSize; j++) {
            arr[numsSize * i + j] = nums[j];
        }
    }
    
    for(i = first; i < first + numsSize - 1; i++) {
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}
