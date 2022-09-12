/**
 * @param {string[]} strs
 * @return {string[][]}
 */
 var groupAnagrams = function(strs) {
  let map = new Map()
  
  strs.forEach(el => {
      let arr = el.split('')
      arr.sort()
      let tmp = arr.join('')
      if(map.has(tmp)) map.get(tmp).push(el)
      else map.set(tmp, [el])
  })
  
  let ans = []
  
  map.forEach((val, key) => ans.push(val))
  
  return ans
};