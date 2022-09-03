class MyHashMap {
    
  class Entry {
      int key, val;
      public Entry(int key, int val) {
          this.key = key;
          this.val = val;
      }
  }
  
  List<Entry>[] map;
  int sz = 769;
      
  public MyHashMap() {
      map = new LinkedList[sz];
  }
  
  public void put(int key, int value) {
      int bucket = key % sz;
      if(map[bucket] == null) {
          map[bucket] = new LinkedList<>();
          map[bucket].add(new Entry(key, value));
          return;
      }
      for(Entry entry:map[bucket]) {
          if(entry.key == key) {
              entry.val = value;
              return;
          }
      }
      map[bucket].add(new Entry(key, value));
  }
  
  public int get(int key) {
      int bucket = key % sz;
      if(map[bucket] == null) return -1;
      for(Entry entry:map[bucket]) {
          if(entry.key == key) return entry.val;
      }
      return -1;
  }
  
  public void remove(int key) {
      int bucket = key % sz;
      Entry toRemove = null;
      if(map[bucket] == null) return;
      for(Entry entry:map[bucket]) {
          if(entry.key == key) {
              toRemove = entry;
              break;
          }
      }
      if(toRemove == null) return;
      map[bucket].remove(toRemove);
  }
}

/**
* Your MyHashMap object will be instantiated and called as such:
* MyHashMap obj = new MyHashMap();
* obj.put(key,value);
* int param_2 = obj.get(key);
* obj.remove(key);
*/