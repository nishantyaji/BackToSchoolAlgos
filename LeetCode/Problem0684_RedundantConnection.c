#include <stdio.h>
#include <stdlib.h>

int find(int * parent, int * size, int len, int i) {
	if(parent[i] != i) {
		parent[i] = find(parent, size, len, parent[i]);
	}
	return parent[i];
}

void unions(int * parent, int * size, int len, int i, int j) {
	int ipar = find(parent, size, len, i);
	int jpar = find(parent, size, len, j);
	if(ipar == jpar) {
		return;
	}
	int isize = size[i];
	int jsize = size[j];

	if(isize < jsize) {
		parent[ipar] = jpar;
		size[jpar] += size[i];
	} else {
		parent[jpar] = ipar;
		size[ipar] += size[j];
	}
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
	int set[1001];
	int i = 0, j = 0;
	for(i = 0; i < 1001; i++) {
		set[i] = 0;
	}
	set[0] = 1;
	int mx = -1, n = 0;
	for(i = 0; i < edgesSize; i++) {
		mx = edges[i][0] > mx ? edges[i][0] : mx;
		mx = edges[i][1] > mx ? edges[i][1] : mx;
	}
	n = mx;

	// init
	int * parent = (int *)malloc(sizeof(int) * n);
	int * size = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++) {
		parent[i] = i;
		size[i] = 1;
	}

	* returnSize = 2;
	int * res = (int *)malloc(sizeof(int) * 2);
	for(i = 0; i < edgesSize; i++) {
		int find0 = find(parent, size, n, edges[i][0] - 1);
		int find1 = find(parent, size, n, edges[i][1] - 1);
		if(set[edges[i][0]] > 0 && set[edges[i][1]] > 0 && find0 == find1) {
			res[0] = edges[i][0];
			res[1] = edges[i][1];
		} else {
			set[edges[i][0]] = 1;
			set[edges[i][1]] = 1;
			unions(parent, size, n, edges[i][0] - 1, edges[i][1] - 1);
		}
	}
	return res;
}

int main()
{
	int n = 10;
	int ** edges = (int ** )malloc(sizeof(int *) * n);
	int i = 0;

	for(i = 0; i < n; i++) {
		edges[i] = (int *) malloc(sizeof(int *) * 2);
	}
	edges[0][0] = 9;
	edges[0][1] = 10;

	edges[1][0] = 5;
	edges[1][1] = 8;

	edges[2][0] = 2;
	edges[2][1] = 6;

	edges[3][0] = 1;
	edges[3][1] = 5;

	edges[4][0] = 3;
	edges[4][1] = 8;

	edges[5][0] = 4;
	edges[5][1] = 9;

	edges[6][0] = 8;
	edges[6][1] = 10;

	edges[7][0] = 4;
	edges[7][1] = 10;

	edges[8][0] = 6;
	edges[8][1] = 8;

	edges[9][0] = 7;
	edges[9][1] = 9;

	int * colSize = (int *) malloc(sizeof(int));
	* colSize = 2;
	int * returnSize = (int *)malloc(sizeof(int));
	int * res = findRedundantConnection(edges, n, colSize, returnSize);
	for(i = 0; i < 2; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}
