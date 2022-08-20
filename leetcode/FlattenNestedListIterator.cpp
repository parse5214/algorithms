/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int idx=0;
    vector<int> v;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto a:nestedList){
            flatten(a);
        }
    }
    
    void flatten(NestedInteger& a){
        if(a.isInteger()) v.push_back(a.getInteger());
        else{
            for(auto b:a.getList()) flatten(b);
        }
    } 
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx < v.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */