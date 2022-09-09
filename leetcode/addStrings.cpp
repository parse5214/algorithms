class Solution {
public:
    string addStrings(string num1, string num2) {
        int carr = 0;
        
        int n = num1.size() - 1;
        int m = num2.size() - 1;
        
        string ans;
        
        while(n >= 0 || m >= 0 || carr != 0) {
            int a = (n<0)? 0:num1[n]-'0';
            int b = (m<0)? 0:num2[m]-'0';
            int num = a + b + carr;
            carr = num/10;
            num %= 10;
            n--;
            m--;
            ans.push_back(num + '0');
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};