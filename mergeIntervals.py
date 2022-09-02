

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []
        sortedIntervals = sorted(intervals, key = itemgetter(0))
        
        ans.append(sortedIntervals[0])
        
        for i in range(1, len(intervals)):
            if(ans[-1][1] < sortedIntervals[i][0]):
                ans.append(sortedIntervals[i])
            else:
                ans[-1][1] = max(ans[-1][1], sortedIntervals[i][1])
        
        return ans