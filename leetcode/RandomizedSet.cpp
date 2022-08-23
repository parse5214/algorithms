class RandomizedSet {
public:
    unordered_map<int, int> myMap;
    vector<int> v;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool flag = true;
        if(myMap.count(val)) flag = false;
        if(flag) {
            myMap[val] = v.size();
            v.push_back(val);
        }
        return flag;
    }
    
    bool remove(int val) {
        bool flag = true;
        if(!myMap.count(val)) flag = false;
        if(flag) {
            int idx = myMap[val];
            v[idx] = v[v.size()-1];
            myMap[v[idx]] = idx;
            v.pop_back();
            myMap.erase(val);
        }
        return flag;
    }
    
    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */