class Solution {
  public int[][] merge(int[][] intervals) {
      int n = intervals.length;
      Arrays.sort(intervals, Comparator.comparingInt(o -> o[0]));
      List<List<Integer>> res = new ArrayList<>();
      res.add(new ArrayList<Integer>(Arrays.asList(intervals[0][0], intervals[0][1])));
      
      for(int i=1; i<n; i++) {
          if(res.get(res.size()-1).get(1) < intervals[i][0]) res.add(new ArrayList<>(Arrays.asList(intervals[i][0], intervals[i][1])));
          else res.get(res.size()-1).set(1, Math.max(res.get(res.size()-1).get(1), intervals[i][1]));
      }
      
      int m = res.size();
      int[][] ans = new int[m][2];
      
      for(int i=0; i<m; i++) {
          ans[i][0] = res.get(i).get(0);
          ans[i][1] = res.get(i).get(1);
      }
      
      return ans;
  }
}