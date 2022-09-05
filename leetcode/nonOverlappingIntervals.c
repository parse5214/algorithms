
int compare(const void* xVoid, const void* yVoid) {
    int* x = *(int**) xVoid;
    int* y = *(int**) yVoid;
    if(x[0] != y[0]) return x[0]-y[0];
    else return x[1]-y[1];
}


int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int n= intervalsSize;
    *intervalsColSize = 2;
    qsort(intervals, n, sizeof(intervals[0]), compare);
    
    int r = intervals[0][1];
    int ans = 0;
    
    for(int i=1; i<n; i++){
        if(r > intervals[i][0]) {
            ans++;
            if(r > intervals[i][1]) r = intervals[i][1];
        }else r = intervals[i][1];
    }
    
    return ans;
}