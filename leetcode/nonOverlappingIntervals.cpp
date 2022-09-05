class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        int r = intervals[0][1];
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            if(r > intervals[i][0]) {
                ans++;
                if(r > intervals[i][1]) r = intervals[i][1];
            }else r = intervals[i][1];
        }
        
        return ans;
    }
};