class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0;
        int majority = 0;
        
        for( int n:nums ) {
            
            if( cnt == 0 ) majority = n;
            
            if( majority == n) cnt++;
            else cnt--;
            
        }
        
        return majority;
        
    }
};