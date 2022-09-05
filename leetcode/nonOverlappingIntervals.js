/**
 * @param {number[][]} intervals
 * @return {number}
 */
 var eraseOverlapIntervals = function(intervals) {
  intervals.sort(([a, b], [c, d]) => a-c||b-d)
  let n = intervals.length
  let r = intervals[0][1]
  let ans = 0
  
  for(let i=1; i<n; i++) {
      if(r > intervals[i][0]) {
          ans++
          if(r > intervals[i][1]) r = intervals[i][1]
      }else r = intervals[i][1]
  }
  
  return ans
};