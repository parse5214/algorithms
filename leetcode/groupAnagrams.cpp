class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        
        unordered_map<string, vector<string>> myMap;
        
        for(string& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            myMap[tmp].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto& it : myMap) ans.push_back(it.second);
        
        return ans;
    }
};