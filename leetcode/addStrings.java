class Solution {
  public String addStrings(String num1, String num2) {
      
      int n = num1.length();
      int m = num2.length();
      int carr = 0;
      
      StringBuffer sb = new StringBuffer();
      
      while(n > 0 || m > 0 || carr != 0) {
          int a = (n < 1)? 0 : num1.charAt(n-1) - '0';
          int b = (m < 1)? 0 : num2.charAt(m-1) - '0';
          int num = a + b + carr;
          carr = num/10;
          num %= 10;
          sb.append(num);
          n--;
          m--;
      }
      
      sb.reverse();
      
      String str = sb.toString();
      
      return str;
  }
}