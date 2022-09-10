class Solution {
  public boolean wordPattern(String pattern, String s) {
      
      
      HashMap<Character, String> map1 = new HashMap<>();
      HashMap<String, Character> map2 = new HashMap<>();
      
      List<String> sSplit = new ArrayList<>();
      int n = s.length();
      StringBuffer sb = new StringBuffer();
      
      for(int i = 0; i < n; i++) {
          if(s.charAt(i) == ' ') {
              sSplit.add(sb.toString());
              sb.delete(0, sb.length());
          }else sb.append(s.charAt(i));
      }
      
      sSplit.add(sb.toString());
      
      if(pattern.length() != sSplit.size()) return false;
      
      for(int i = 0; i < pattern.length(); i++) {
          if(map1.containsKey(pattern.charAt(i))) {
              if(!map1.get(pattern.charAt(i)).equals(sSplit.get(i))) return false;
          }else map1.put(pattern.charAt(i), sSplit.get(i));
          
          if(map2.containsKey(sSplit.get(i))) {
              if(map2.get(sSplit.get(i)) != pattern.charAt(i)) return false;
          }else map2.put(sSplit.get(i), pattern.charAt(i));
      }
      
      return true;
  }
}