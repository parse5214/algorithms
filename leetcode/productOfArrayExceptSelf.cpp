class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n= nums.size();
        vector<int> ans(n);
        int prod = 1;
        
        for(int i=0; i<n-1; i++) {
            prod *= nums[i];
            ans[i] = prod;
        }
        
        prod = 1;
        
        for(int i=n-1; i>0; i--) {
            ans[i] = prod * ans[i-1];
            prod *= nums[i];
        }
        
        ans[0] = prod;
        
        return ans;
    }
};