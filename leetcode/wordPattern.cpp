class Solution {
public:
    vector<string> split(string s) {
        vector<string> ans;
        int n = s.size();
        string tmp;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                ans.push_back(tmp);
                tmp.clear();
            }else tmp.push_back(s[i]);
        }
        
        ans.push_back(tmp);
        
        return ans;
    }
    
    bool wordPattern(string pattern, string s) {
        
        vector<string> sSplit = split(s);
        
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        
        if(pattern.size() != sSplit.size()) return false;
        
        for(int i = 0; i < pattern.size(); i++) {
            if(map1.find(pattern[i]) != map1.end()) {
                if(map1[pattern[i]] != sSplit[i]) return false;
            }else map1[pattern[i]] = sSplit[i];
            
            if(map2.find(sSplit[i]) != map2.end()) {
                if(map2[sSplit[i]] != pattern[i]) return false;
            }else map2[sSplit[i]] = pattern[i];
        }
        
        return true;
    }
};