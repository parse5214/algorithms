class Solution {
  public int majorityElement(int[] nums) {

      int majority = 0;
      int cnt = 0;
      
      for( int n:nums ) {
          
          if( cnt == 0 ) majority = n;
          
          if( majority == n ) cnt++;
          else cnt--;
          
      }
      
      return majority;
      
  }
}