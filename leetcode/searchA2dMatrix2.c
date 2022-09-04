

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize;
    int n = *matrixColSize;
    
    int row = 0;
    int col = n-1;
    
    while(row < m && col >= 0) {
        if(*(*(matrix+row)+col) == target) return true;
        else if(*(*(matrix+row)+col) < target) row++;
        else col--;
    }
    
    return false;
}