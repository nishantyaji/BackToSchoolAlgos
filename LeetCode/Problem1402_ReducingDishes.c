#include <stdio.h>

int compare(const void *a, const void *b) {
    int * first = (int *) a;
    int * second = (int *) b;
    return *second - *first;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    qsort(satisfaction, satisfactionSize, sizeof(int), compare);
    int res = 0, runSum = 0, cumSum = 0, i = 0;
    for(i = 0; i < satisfactionSize; i++) {
        cumSum += satisfaction[i];
		runSum += cumSum;
		res = res > runSum ? res : runSum;
    }
	return res;
}

int main()
{
    int d[5] = {-1,-8,0,5,-7};
    int res = maxSatisfaction(d, 5);
    printf("\n%d", res);
    return 0;
}
