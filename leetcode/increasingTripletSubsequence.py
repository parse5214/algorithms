class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        flag = True
        n = len(nums)
        low = -1
        high = -1
        
        for i in range(n):
            if(flag and i < n-1 and nums[i] < nums[i+1]):
                flag = False
                low = nums[i]
                high = nums[i+1]
            elif(not flag):
                if(nums[i] <= low): low = nums[i]
                else:
                    if(nums[i] <= high): high = nums[i]
                    else: return True
        
        return False
                    