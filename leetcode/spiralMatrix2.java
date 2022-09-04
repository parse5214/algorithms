class Solution {
  public int[][] generateMatrix(int n) {
      
      int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      
      int[][] matrix = new int[n][n];
      
      int s = 0;
      int i = 0;
      int j = 0;
      
      for(int k = 1; k <= n*n; k++) {
          matrix[i][j] = k;
          i += dir[s][0];
          j += dir[s][1];
          if(i >= n || i < 0 || j >= n || j < 0 || matrix[i][j] != 0) {
              i -= dir[s][0];
              j -= dir[s][1];
              s = (s+1)%4;
              i += dir[s][0];
              j += dir[s][1];
          }
      }
      
      return matrix;
      
  }
}