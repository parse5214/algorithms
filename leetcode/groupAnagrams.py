class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        for i in strs:
            li = list(i)
            li.sort()
            tmp = ''.join(li)
            
            if tmp in dic: dic[tmp].append(i)
            else: dic[tmp] = [i]
        
        
        ans = []
        for i in dic.values(): ans.append(i)
            
        return ans