/*
 * @param {number[][]} intervals
 * @return {number[][]}
 */
 var merge = function(intervals) {
  intervals.sort(function(x, y) {
      if(x[0] < y[0]) return -1;
      if(x[0] > y[0]) return 1;
      if(x[0] === y[0]) return 0;
  })
  let ans = [];
  ans.push(intervals[0]);
  for(let i=1; i<intervals.length; i++) {
      if(ans[ans.length-1][1] < intervals[i][0]) ans.push(intervals[i]);
      else ans[ans.length-1][1] = (ans[ans.length-1][1]>intervals[i][1]) ? ans[ans.length-1][1]:intervals[i][1];
  }
  
  return ans;
};