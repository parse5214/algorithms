class Solution {
  public int eraseOverlapIntervals(int[][] intervals) {
      Arrays.sort(intervals, (a, b) -> {
          if(a[0] != b[0]) return a[0]-b[0];
          else return a[1]-b[1];
      });
      
      int n = intervals.length;
      int r = intervals[0][1];
      int ans = 0;
      
      for(int i=1; i<n; i++) {
          if(r > intervals[i][0]) {
              ans++;
              if(r > intervals[i][1]) r = intervals[i][1];
          }else r = intervals[i][1];
      }
      
      return ans;
  }
}