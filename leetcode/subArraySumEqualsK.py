class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        
        myMap = {0:1}
        partialSum = 0
        ans = 0
        
        for num in nums:
            partialSum += num
            key = partialSum - k
            
            if key in myMap: ans += myMap[key]
            
            if partialSum in myMap: myMap[partialSum] += 1
            else: myMap[partialSum] = 1
            
        return ans