#include <stdio.h>
#include <stdlib.h>

int maxChunksToSorted(int* arr, int arrSize) {
    int * prefixMax = (int *) malloc(sizeof(int) * arrSize);
    int * suffixMin = (int *) malloc(sizeof(int) * arrSize);

    int mn = 1000001, mx = -1, i = 0;
    for(i = 0; i < arrSize; i++) {
        mx = mx > arr[i] ? mx : arr[i];
        mn = mn < arr[arrSize - 1 - i] ? mn : arr[arrSize - 1 - i];
        prefixMax[i] = mx;
        suffixMin[arrSize - 1 - i] = mn;
    }
    
    int chunk = 0;
    for(i = 0; i < arrSize; i++) {
        if(i == 0 && arr[i] == i) chunk++;
        else if(i > 0 && i < arrSize- 1 && prefixMax[i] <= i && suffixMin[i+1] > i) chunk++;
        else if(i == arrSize - 1 && prefixMax[i] <= i) chunk++;
    }
    return chunk;
}

int main()
{
    int arr[5] = {1,0,2,3,4};
    printf("Hello World");
    printf("\n%d", maxChunksToSorted(arr, 5));
    return 0;
}
