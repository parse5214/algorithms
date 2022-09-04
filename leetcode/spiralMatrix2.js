/**
 * @param {number} n
 * @return {number[][]}
 */
 var generateMatrix = function(n) {
  let matrix = Array(n);
  for(let i=0; i<n; i++) matrix[i] = Array(n).fill(0);
  
  let dir = [0, 1, 0, -1];
  
  let s = 0;
  let i = 0;
  let j = 0;
  
  for(let k=1; k<=n*n; k++) {
      matrix[i][j] = k;
      i += dir[s];
      j += dir[(s+1)%4];
      if(i<0 || i==n || j<0 || j==n || matrix[i][j]!=0) {
          i -= dir[s];
          j -= dir[(s+1)%4];
          s = (s+1)%4;
          i += dir[s];
          j += dir[(s+1)%4];
      }
  }
  
  return matrix;
};