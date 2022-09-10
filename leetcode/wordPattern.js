/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
 var wordPattern = function(pattern, s) {
  let map1 = new Map()
  let map2 = new Map()
  
  let sSplit = s.split(" ")
  
  if(pattern.length != sSplit.length) return false
  
  for(let i = 0; i < pattern.length; i++) {
      if(map1.has(pattern[i])) {
          if(map1.get(pattern[i]) != sSplit[i]) return false
      }else map1.set(pattern[i], sSplit[i])
      
      if(map2.has(sSplit[i])) {
          if(map2.get(sSplit[i]) != pattern[i]) return false
      }else map2.set(sSplit[i], pattern[i])
  }
  
  return true
};