

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* ans = (int*) malloc(sizeof(int)* *returnSize);
    int prod = 1;
    
    for(int i = 0; i < *returnSize - 1; i++) {
        prod *= *(nums + i);
        *(ans + i) = prod;
    }
    
    prod = 1;
    
    for(int i = *returnSize - 1; i > 0; i--) {
        *(ans + i) = *(ans + i - 1) * prod;
        prod *= *(nums + i);
    }
    
    *ans = prod;
    
    return ans;
}