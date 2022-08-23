class RandomizedSet {
    
  Map<Integer, Integer> myMap = new HashMap<>();
  List<Integer> li = new ArrayList<>();
  
  public RandomizedSet() {
      
  }
  
  public boolean insert(int val) {
      boolean flag = true;
      if(myMap.containsKey(val)) flag = false;
      if(flag) {
          myMap.put(val, li.size());
          li.add(val);
      }
      return flag;
  }
  
  public boolean remove(int val) {
      boolean flag = true;
      if(!myMap.containsKey(val)) flag = false;
      if(flag) {
          int idx = myMap.get(val);
          li.set(idx, li.get(li.size()-1));
          myMap.put(li.get(idx), idx);
          myMap.remove(val);
          li.remove(li.size()-1);
      }
      return flag;
  }
  
  public int getRandom() {
      int idx = (int)Math.floor(Math.random()*li.size());
      return li.get(idx);
  }
}

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* boolean param_1 = obj.insert(val);
* boolean param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/