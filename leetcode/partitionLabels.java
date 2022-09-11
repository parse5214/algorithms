class Solution {

  public List<Integer> partitionLabels(String s) {
      int last[] = new int[26];
      for(int i = 0; i < s.length(); i++) last[s.charAt(i) - 'a'] = i;
      
      int l = -1;
      int r = 0;
      List<Integer> ans = new ArrayList<>();
      
      for(int i = 0; i < s.length(); i++) {
          r = (r > last[s.charAt(i) - 'a'])? r : last[s.charAt(i) - 'a'];
          if(i == r) {
              ans.add(r - l);
              l = i;
          }
      }
      
      return ans;
  }
}