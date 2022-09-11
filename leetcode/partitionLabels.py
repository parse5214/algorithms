class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        
        li = [0 for i in range(26)]
        
        for i in range(len(s)): li[ord(s[i]) - ord('a')] = i
        
        ans = []
        l = -1
        r = 0
        
        for i in range(len(s)):
            r = r if r > li[ord(s[i]) - ord('a')] else li[ord(s[i]) - ord('a')]
            if r == i:
                ans.append(r - l)
                l = i
        
        return ans
            