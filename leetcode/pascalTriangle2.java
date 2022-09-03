class Solution {
  public List<Integer> getRow(int rowIndex) {
      
      int[] prev;
      int[] tmp = new int[1];
      tmp[0] = 1;
      
      List<Integer> ans = new ArrayList<>();
      
      for(int i = 0; i <= rowIndex; i++) {
          prev = tmp;
          tmp = new int[i+1];
          for(int j=0; j <= i; j++) {
              if(j == 0) tmp[j] = prev[j];
              else if(j == i) tmp[j] = prev[j-1];
              else tmp[j] = prev[j] + prev[j-1];
          }
          
          if(i == rowIndex) {
              for(int num:tmp) ans.add(num);
              break;
          }
      }
      
      return ans;
  }
}