/**
 * @param {number[]} nums
 * @return {boolean}
 */
 var increasingTriplet = function(nums) {
  let n = nums.length
  let min = -1
  let max = -1
  let flag = true
  
  for(let i=0; i<n; i++) {
      if(flag && i<n-1 && nums[i]<nums[i+1]) {
          flag = false
          min = nums[i]
          max = nums[i+1]
      }else if(!flag) {
          if(nums[i] <= min) min = nums[i]
          else {
              if(nums[i] <= max) max = nums[i]
              else return true
          }
      }
  }
  
  return false
};