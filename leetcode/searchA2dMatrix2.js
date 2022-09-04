/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
 var searchMatrix = function(matrix, target) {
  let m = matrix.length
  let n = matrix[0].length
  
  let row = m - 1
  let col = 0
  
  while(col < n && row >= 0) {
      if(matrix[row][col] === target) return true
      else if(matrix[row][col] > target) row--;
      else col++;
  }
  
  return false
};