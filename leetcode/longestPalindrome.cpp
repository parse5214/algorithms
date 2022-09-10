class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(26);
        vector<int> v2(26);
        
        for(char c : s) {
            if(islower(c)) v[c-'a']++;
            else v2[c-'A']++;
        }
        
        int sum = 0;
        bool flag = false;
        
        for(int i = 0; i < 26; i++) {
            
            if(!(v[i]&1)) sum += v[i];
            else {
                if(v[i] > 1) sum += v[i] - 1;
                flag = true;
            } 
            
            if(!(v2[i]&1)) sum += v2[i];
            else {
                if(v2[i] > 1) sum += v2[i] - 1;
                flag = true;
            } 
            
        }
        
        if(flag) sum++;
        
        return sum;
    }
};