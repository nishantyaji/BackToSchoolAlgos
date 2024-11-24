long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int i = 0, j = 0, neg = 0, smallest = 100001;
    long long sum = 0; 
    for(i = 0; i < matrixSize; i++) {
        for(j = 0; j < matrixSize; j++) {
            sum += abs(matrix[i][j]);
            neg = (matrix[i][j] < 0) ? neg + 1 : neg;
            smallest = abs(matrix[i][j]) < smallest ? abs(matrix[i][j]) : smallest;
        }
    }

    if(neg % 2 == 0) {
        return sum;
    } else{
        return sum - 2 * smallest;
    }

}
