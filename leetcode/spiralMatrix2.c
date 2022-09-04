

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    
    int** ans = (int**) malloc(sizeof(int*) * n);
    *returnSize = n;
    *returnColumnSizes = (int*) malloc(sizeof(int) * n);
    for(int i=0; i<n; i++) {
        *(ans+i) = (int*) malloc(sizeof(int) * n);
        *(*returnColumnSizes + i) = n;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            *(*(ans+i)+j) = 0;
        }
    }
    
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int s = 0;
    int i = 0;
    int j = 0;
    
    for(int k=1; k<=n*n; k++) {
        *(*(ans+i)+j) = k;
        i += dir[s][0];
        j += dir[s][1];
        if(i<0 || i>=n || j<0 || j>=n || *(*(ans+i)+j)!=0) {
            i -= dir[s][0];
            j -= dir[s][1];
            s = (s+1)%4;
            i += dir[s][0];
            j += dir[s][1];
        }
    }
    
    return ans;
    
}