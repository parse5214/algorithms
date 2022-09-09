/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
 var subarraySum = function(nums, k) {
  let myMap = new Map()
  
  let ans = 0
  let sum = 0
  
  myMap.set(0, 1)
  
  for(let i = 0; i < nums.length; i++) {
      sum += nums[i]
      let find = sum - k
      
      if(myMap.get(find) != undefined) ans += myMap.get(find)
      
      if(myMap.get(sum) == undefined) myMap.set(sum, 1)
      else myMap.set(sum, myMap.get(sum) + 1)
  }
  
  return ans
};