/**
 * @param {string} s
 * @return {number[]}
 */
 var partitionLabels = function(s) {
  let last = Array(26)
  let s2 = s.split('');
  
  s2.forEach((el, i) => last[el.charCodeAt(0) - 'a'.charCodeAt(0)] = i)
  
  let l = -1
  let r = 0
  let ans = []
  
  s2.forEach((el, i) => {
      r = (r > last[el.charCodeAt(0) - 'a'.charCodeAt(0)]) ? r : last[el.charCodeAt(0) - 'a'.charCodeAt(0)]
      if(r == i) {
          ans.push(r - l)
          l = i
      }
  })
  
  return ans
};