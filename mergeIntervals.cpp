class Solution {
public:
    static bool sortByLeft(vector<int>& a, vector<int>& b) {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(), sortByLeft);
        int l = inter[0][0];
        int r = inter[0][1];
        vector<vector<int>> ans;
        for(int i=1; i<inter.size(); i++) {
            if(inter[i][0] <= r && inter[i][1] > r) r = inter[i][1];
            else if(inter[i][0] <= r) continue;
            else {
                ans.push_back({l, r});
                l = inter[i][0];
                r = inter[i][1];
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};