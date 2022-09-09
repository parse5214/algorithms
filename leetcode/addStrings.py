class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        n = len(num1)
        m = len(num2)
        
        carr = 0
        ans = ""
        
        while(n > 0 or m > 0 or carr != 0):
            a = 0 if n <= 0 else ord(num1[n - 1]) - ord('0')
            b = 0 if m <= 0 else ord(num2[m - 1]) - ord('0')
            
            num = a + b + carr
            
            carr = num//10
            num %= 10
            
            ans += chr(num + ord('0'))
            n -= 1
            m -= 1
            
        
        ans = ans[::-1]
        return ans