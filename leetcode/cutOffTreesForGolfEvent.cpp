class Solution {
public:
    
    static bool customSort(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        
        int ans = 0;
        
        int m = forest.size();
        int n = forest[0].size();
        vector<vector<int>> heightAndCoord;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(forest[i][j] > 1) heightAndCoord.push_back({forest[i][j], i, j});
            }
        }
        
        sort(heightAndCoord.begin(), heightAndCoord.end(), customSort);
        
        vector<int> dir = {0, 1, 0, -1};
        
        for(int i = 0; i < heightAndCoord.size(); i++) {
            
            int xStart, yStart, xEnd, yEnd;
            
            if(i == 0) {
                
                xStart = 0;
                yStart = 0;
                xEnd = heightAndCoord[i][1];
                yEnd = heightAndCoord[i][2];
                
            }else {
                
                xStart = heightAndCoord[i - 1][1];
                yStart = heightAndCoord[i - 1][2];
                xEnd = heightAndCoord[i][1];
                yEnd = heightAndCoord[i][2];
                
            }
            
            vector<vector<int>> used(m, vector<int>(n, 0));
            
            queue<pair<int, int>> q;
            
            q.push({xStart, yStart});
            
            used[xStart][yStart] = 1;
            
            bool flag = true;
            
            while(!q.empty()) {
                
                int sz = q.size();
                
                for(int k = 0; k < sz; k++) {
                    pair p = q.front();
                    q.pop();

                    int x = p.first;
                    int y = p.second;

                    if(x == xEnd && y == yEnd) {
                        flag = false;
                        break;
                    }

                    for(int j = 0; j < 4; j++) {
                        int nextX = x + dir[j];
                        int nextY = y + dir[(j + 1) % 4];

                        if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || used[nextX][nextY] == 1 || forest[nextX][nextY] == 0) continue;

                        used[nextX][nextY] = 1;

                        q.push({nextX, nextY});
                    }
                }
                
                if(!flag) break;
                
                ans++;
            }
            
            if(flag) return -1;
        }
        
        return ans;
        
    }
};