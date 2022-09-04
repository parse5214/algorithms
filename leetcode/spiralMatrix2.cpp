class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        vector<int> dir{0, 1, 0, -1};
        
        int s = 0;
        int i = 0;
        int j = 0;
        
        for(int k=1; k<=n*n; k++) {
            ans[i][j] = k;
            i += dir[s];
            j += dir[(s+1)%4];
            if(i<0 || i==n || j<0 || j==n || ans[i][j]!=0) {
                i -= dir[s];
                j -= dir[(s+1)%4];
                s = (s+1)%4;
                i += dir[s];
                j += dir[(s+1)%4];
            }
        }
        
        return ans;
    }
};