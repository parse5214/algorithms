class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        sSplit = s.split(' ')
        
        if(len(pattern) != len(sSplit)): return False
        
        map1 = {}
        map2 = {}
        
        for i in range(len(pattern)):
            if pattern[i] in map1:
                if map1[pattern[i]] != sSplit[i]: return False
            else: map1[pattern[i]] = sSplit[i]
            
            if sSplit[i] in map2:
                if map2[sSplit[i]] != pattern[i]: return False
            else: map2[sSplit[i]] = pattern[i]
                
        return True
                