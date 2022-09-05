/**
 * @param {number[]} nums
 * @return {number[]}
 */
 var productExceptSelf = function(nums) {
  let n = nums.length
  let ans = Array(n)
  let prod = 1
  
  for(let i = 0; i < n - 1; i++) {
      prod *= nums[i]
      ans[i] = prod
  }
  
  prod = 1
  
  for(let i = n-1; i > 0; i--) {
      ans[i] = prod * ans[i-1]
      prod *= nums[i]
  }
  
  ans[0] = prod
  
  return ans
};