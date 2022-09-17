/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */

 function gcd(a, b) {
  if(b === 0) return a
  return gcd(b, a % b)
}

var gcdOfStrings = function(str1, str2) {
  if(!((str1 + str2) === (str2 + str1))) return ""
  let val = gcd(str1.length, str2.length)
  return str1.substring(0, val)
};