class Solution {
  public int[] productExceptSelf(int[] nums) {
      int n = nums.length;
      int[] ans = new int[n];
      int prod = 1;
      
      for(int i = 0; i < n-1; i++) {
          prod *= nums[i];
          ans[i] = prod;
      }
      
      prod = 1;
      
      for(int i = n-1; i > 0; i--) {
          ans[i] = ans[i-1] * prod;
          prod *= nums[i];
      }
      
      ans[0] = prod;
      
      return ans;
  }
}