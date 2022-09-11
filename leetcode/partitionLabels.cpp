class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        for(int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;
        
        int l = -1;
        int r = 0;
        vector<int> ans;
        
        for(int i = 0; i < s.size(); i++) {
            r = (r > last[s[i] - 'a']) ? r : last[s[i] - 'a'];
            if(r == i) {
                ans.push_back(r - l);
                l = i;
            }
        }
        
        return ans;
    }
};