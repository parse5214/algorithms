class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int cnt0 = 0;
        int cnt1 = 0;
        
        for(int& n:nums) {
            if(n == 0) cnt0++;
            else if(n == 1) cnt1++;
        }
        
        for(int& n:nums) {
            if(cnt0-- > 0) n = 0;
            else if(cnt1-- > 0) n = 1;
            else n = 2;
        }
        
    }
};