class Solution(object):
    
    def gcd(self, a, b):
        if(b == 0): return a
        return self.gcd(b, a % b)
    
    
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        if(not((str1 + str2) == (str2 + str1))): return ""
        val = self.gcd(len(str1), len(str2))
        return str1[:val]