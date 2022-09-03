/**
 * @param {number} rowIndex
 * @return {number[]}
 */
 var getRow = function(rowIndex) {
  let tmp = [1]
  
  for(let i = 0; i <= rowIndex; i++) {
      let prev = [...tmp]
      
      
      for(let j = 0; j <= i; j++) {
          if(j == 0) tmp[j] = prev[j]
          else if(j == i) tmp[j] = prev[j-1]
          else tmp[j] = prev[j-1] + prev[j]
      }
      
      if(i == rowIndex) return tmp
  }
};