class Solution {
  public int singleNumber(int[] nums) {
      int n = 0;
      for(var i:nums) n ^= i;
      return n;
  }
}