#include <stdio.h>
#include <stdlib.h>

int countServers(int** grid, int gridSize, int* gridColSize) {
    int * rowFlags = (int *) malloc(sizeof(int) * gridSize);   
    int * colFlags = (int *) malloc(sizeof(int) * (*gridColSize));
    int i = 0;
    for(i = 0; i < gridSize; i++) {
        rowFlags[i] = 0;
    }
    for(i = 0; i < * gridColSize; i++) {
        colFlags[i] = 0;
    }
    
    int total = 0, j = 0;
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < *gridColSize; j++) {
            if(grid[i][j]) {
                rowFlags[i]++;
                colFlags[j]++;
                total++;
            }
        }
    }
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < *gridColSize; j++) {
            if(grid[i][j]) {
                if(rowFlags[i] == 1 && colFlags[j] == 1) {
                total--;
                }
            }
        }
    }
    return total;
}

int main()
{
    int rows = 2, cols = 2;
    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }
    grid[0][0] = 1;
    grid[0][1] = 0;
    grid[1][0] = 1;
    grid[1][1] = 1;
    printf("\n%d", countServers(grid, rows, &cols));
    return 0;
}
