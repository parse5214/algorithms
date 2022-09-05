class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool flag = true;
        int min = -1, max = -1;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(flag && i < n-1 && nums[i] < nums[i+1]) {
                flag = false;
                min = nums[i];
                max = nums[i+1];
            }else if(!flag) {
                if(nums[i] <= min) min = nums[i];
                else{
                    if(nums[i] <= max) max = nums[i];
                    else return true;
                }
            }
        }
        
        return false;
    }
};