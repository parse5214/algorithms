

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize){
    int n = strlen(s);
    int* last = (int*) calloc(26, sizeof(int));
    
    
    for(int i = 0; i < n; i++) last[s[i] - 'a'] = i;
        
    int l = -1;
    int r = 0;
    int* ans = (int*) calloc(26, sizeof(int));
    *returnSize = 0;
    
    for(int i = 0; i < n; i++) {
        r = (r > last[s[i] - 'a']) ? r : last[s[i] - 'a'];
        if(r == i) {
            ans[(*returnSize)++] = r - l;
            l = i;
        }
    }
    
    return ans;
}