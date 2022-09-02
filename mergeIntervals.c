

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comp(const void* p1, const void* p2) {
    int* arr1 = *(int**) p1;
    int* arr2 = *(int**) p2;
    return arr1[0] - arr2[0];
}

int* addInterval(int a, int b) {
    int* res = (int*) malloc(sizeof(int)*2);
    res[0] = a;
    res[1] = b;
    return res;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** ans = NULL;
    ans = (int**) malloc(sizeof(int*)*intervalsSize);
    for(int i=0; i<intervalsSize; i++) ans[i] = NULL;
    // sort intervals by start point
    qsort(intervals, intervalsSize, sizeof(intervals[0]), comp);
    ans[(*returnSize)++] = addInterval(intervals[0][0], intervals[0][1]);
    
    for(int i=1; i<intervalsSize; i++) {
        if(ans[(*returnSize)-1][1] < intervals[i][0]) {
            ans[(*returnSize)++] = addInterval(intervals[i][0], intervals[i][1]);
        }else ans[(*returnSize)-1][1] = fmax(ans[(*returnSize)-1][1], intervals[i][1]);
    }
    
    *returnColumnSizes = (int*) malloc(sizeof(int)* *returnSize);
    for(int i=0; i<*returnSize; i++) (*returnColumnSizes)[i] = 2;
    
    return ans;
}