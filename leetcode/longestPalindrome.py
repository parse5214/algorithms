class Solution:
    def longestPalindrome(self, s: str) -> int:
        
        a = [0 for i in range(26)]
        b = [0 for i in range(26)]
        
        ans = 0
        
        for i in s:
            if(i.islower()): a[ord(i) - ord('a')] += 1
            else: b[ord(i) - ord('A')] += 1
                
        flag = False
            
        for i in range(26):
            if(a[i] % 2 == 0): ans += a[i]
            else:
                ans += a[i] - 1
                flag = True
            
            if(b[i] % 2 == 0): ans += b[i]
            else:
                ans += b[i] - 1
                flag = True
        
        if(flag): ans += 1
        
        return ans
            
            