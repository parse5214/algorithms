/**
 * @param {string} s
 * @return {number}
 */
 var longestPalindrome = function(s) {
  let myMap = new Map()
  
  s.split('').forEach(el => {
      if(myMap.get(el) == undefined) myMap.set(el, 1)
      else myMap.set(el, myMap.get(el) + 1)
  })
  
  let ans = 0
  let flag = false
  
  myMap.forEach((val, key) => {
      if(val % 2 == 0) ans += val
      else {
          ans += val - 1
          flag = true
      }
  })
  
  if(flag) ans++
  
  return ans
};