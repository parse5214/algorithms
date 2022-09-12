class Solution {
  public List<List<String>> groupAnagrams(String[] strs) {
      HashMap<String, List<String>> map = new HashMap<>();
      
      for(String str : strs) {
          char[] tmpArray = str.toCharArray();
          Arrays.sort(tmpArray);
          String tmp = new String(tmpArray);
          if(map.containsKey(tmp)) map.get(tmp).add(str);
          else {
              List<String> li = new ArrayList<>();
              li.add(str);
              map.put(tmp, li);
          }
      }
      
      List<List<String>> ans = new ArrayList<>();
      
      for(List<String> li : map.values()) ans.add(li);
      
      return ans;
  }
}