class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        
        matrix = [[0 for i in range(n)] for j in range(n)]
        
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        
        s = 0
        i = 0
        j = 0
        
        for k in range(1, n*n+1):
            matrix[i][j] = k
            i += directions[s][0]
            j += directions[s][1]
            if(i < 0 or i >= n or j < 0 or j >= n or matrix[i][j] != 0):
                i -= directions[s][0]
                j -= directions[s][1]
                s = (s+1)%4
                i += directions[s][0]
                j += directions[s][1]
                
        return matrix
            
            