class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        
        sortedIntervals = sorted(intervals, key=itemgetter(0, 1))
        
        n = len(intervals)
        r = sortedIntervals[0][1]
        ans = 0
        
        for i in range(1, n):
            if(r > sortedIntervals[i][0]):
                ans += 1
                if(r > sortedIntervals[i][1]): r = sortedIntervals[i][1]
            else: r = sortedIntervals[i][1]
        
        return ans
        