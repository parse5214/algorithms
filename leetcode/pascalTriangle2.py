class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        tmp = [1]
        
        for i in range(0, rowIndex + 1):
            prev = tmp
            tmp = [0] * (i + 1)
            for j in range(0, i + 1):
                if(j == 0):
                    tmp[j] = prev[j]
                elif(j == i):
                    tmp[j] = prev[j-1]
                else:
                    tmp[j] = prev[j-1] + prev[j]
                
            if(i == rowIndex): return tmp
        
        return tmp
            