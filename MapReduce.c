#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {return a + b; }
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

int reduce(void * fn, int * arr, int * arrSize, int initVal) {
    int * (*fun)(int, int) = fn;
    int res = initVal;
    int i = 0;
    for(i = 0; i < *arrSize; i++) {
        res = (* fun)(res, arr[i]);
    }
    return res;
}

int main()
{
    printf("Hello World");
    int (*fn)(int) = doubled;
    int (*redfn)(int, int) = add;
    int arr[5] = {1,22, 3, 4, 4};
    int arrSize = 5;
    int * mapRes = map(doubled, arr, &arrSize);
    int i = 0;
    for(i = 0; i < 5; i++) {
        printf("\n%d", mapRes[i]);
    }
    printf("\nReduced: %d", reduce(redfn, mapRes, &arrSize, 0));
    printf("\nReduced chained: %d", reduce(redfn, map(doubled, arr, &arrSize), &arrSize, 0));

    return 0;
}
