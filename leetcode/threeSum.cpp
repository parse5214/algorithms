class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::sort(nums.begin(),nums.end());
        int sz=nums.size();
        std::vector<std::vector<int>> result;
        
        for(int i=0;i<sz;i++){
            
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1;
            int r=sz-1;
            
            while(l<r){
                
                int sum=nums[i]+nums[l]+nums[r];
                
                if(sum>0) r--;
                else if(sum<0) l++;
                else{
                    result.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    while(nums[l]==nums[l-1]&&l<r) l++;
                }
                
            }
        }
        
        return result;
    }
};