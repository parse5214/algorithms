class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int ans = 0;
        int sum = 0;
        int i = 0;
        int n = nums.size();
        
        myMap[sum] = 1;
        
        while(i < n) {
            sum += nums[i];
            int find = sum - k;
            
            if(myMap.find(find) != myMap.end()) ans += myMap[find];
            
            myMap[sum]++;
            i++;
            
        }
        
        return ans;
    }
};