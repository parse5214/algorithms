class Solution {
  public int subarraySum(int[] nums, int k) {
      
      HashMap<Integer, Integer> map = new HashMap<>();
      
      int ans = 0;
      int sum = 0;
      map.put(0, 1);
      
      for(int num : nums) {
          sum += num;
          int find = sum - k;
          
          if(map.containsKey(find)) ans += map.get(find);
          
          if(map.containsKey(sum)) map.replace(sum, map.get(sum) + 1);
          else map.put(sum, 1);
      }
      
      return ans;
  }
}