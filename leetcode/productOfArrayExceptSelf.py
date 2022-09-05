class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0 for i in range(n)]
        prod = 1
        
        for i in range(0, n-1):
            prod *= nums[i]
            ans[i] = prod
            
        prod = 1
        
        for i in range(n-1, 0, -1):
            ans[i] = ans[i-1] * prod
            prod *= nums[i]
        
        ans[0] = prod
        
        return ans