/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
 var addStrings = function(num1, num2) {
  let n = num1.length
  let m = num2.length
  let carr = 0

  let ans = ""
  
  while(n > 0 || m > 0 || carr > 0) {
      let a = (n < 1) ? 0 : Number(num1[n-1])
      let b = (m < 1) ? 0 : Number(num2[m-1])
      let num = a + b + carr
      carr = ~~(num/10)
      num %= 10
      ans += num
      n--;
      m--;
  }
  
  return ans.split("").reverse().join("")
};