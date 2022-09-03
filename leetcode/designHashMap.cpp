class MyHashMap {
private:
    
public:
    
    class Entry {
        public:
            int key, val;
            Entry(int key=-1, int val=-1): key(key), val(val) {}
    };
    
    vector<list<Entry>> map;
    
    int sz = 769;
    
    MyHashMap() {
        map.resize(sz);
    }
    
    void put(int key, int value) {
        int bucket = key % sz;
        auto it = map[bucket].begin();
        while(it != map[bucket].end()) {
            if(it->key == key) {
                it->val = value;
                return;
            }
            it++;
        }
        map[bucket].push_back({key, value});
    }
    
    int get(int key) {
        int bucket = key % sz;
        for(auto& entry: map[bucket]) {
            if(entry.key == key) return entry.val;
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket = key % sz;
        auto it = map[bucket].begin();
        while(it != map[bucket].end()) {
            if(it->key == key) {
                map[bucket].erase(it);
                return;
            }
            it++;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */