#include <stdio.h>
#include <stdlib.h>

int doubled(int a){return 2*a;}

int * map(void * fn, int * arr, int * arrSize) {
    int * (*fun)(int) = fn;
    int * res = (int *) malloc(sizeof(int) * (*arrSize));
    int i = 0;
    for(i = 0; i < *arrSize; i++) {
        res[i] = (*fun)(arr[i]);
    }
    return res;
}

int main()
{
    printf("Hello World");
    int (*fn)(int) = doubled;
    int arr[5] = {1,22, 3, 4, 4};
    int arrSize = 5;
    int * mapRes = map(doubled, arr, &arrSize);
    int i = 0;
    for(i = 0; i < 5; i++) {
        printf("\n%d", mapRes[i]);
    }
    return 0;
}
