

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    
    *returnSize = rowIndex + 1;
    
    int* tmp = (int*) malloc(sizeof(int));
    int* prev = (int*) malloc(sizeof(int));
    
    *tmp = 1;
    
    for(int i = 0; i <= rowIndex; i++) {
        free(prev);
        prev = tmp;
        tmp = (int*) malloc(sizeof(int) * (i + 1));
        
        for(int j = 0; j <= i; j++) {
            if(j == 0) *(tmp + j) = *(prev + j);
            else if(j == i) *(tmp + j) = *(prev + j -1);
            else *(tmp + j) = *(prev + j - 1) + *(prev + j);
        }
        
        if(i == rowIndex) {
            free(prev);
            return tmp;
        }
    }
    
    return tmp;
}