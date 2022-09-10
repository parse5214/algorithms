class Solution {
  public int longestPalindrome(String s) {
      
      int[] arr = new int[26];
      int[] arr2 = new int[26];
      
      for(int i = 0; i < s.length(); i++) {
          if(Character.isLowerCase(s.charAt(i))) arr[s.charAt(i) - 'a']++;
          else arr2[s.charAt(i) - 'A']++;
      }
      
      int sum = 0;
      boolean flag = false;
      
      for(int i = 0; i < 26; i++) {
          if(arr[i] % 2 == 0) sum += arr[i];
          else {
              sum += arr[i] - 1;
              flag = true;
          }
          
          if(arr2[i] % 2 == 0) sum += arr2[i];
          else {
              sum += arr2[i] - 1;
              flag = true;
          }
      }
      
      if(flag) sum++;
      
      return sum;
  }
}