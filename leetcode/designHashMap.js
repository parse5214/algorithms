let myMap = []
let sz = 769
var MyHashMap = function() {
    for(let i=0; i<sz; i++) myMap[i] = []
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
MyHashMap.prototype.put = function(key, value) {
    let bucket = key % sz
    for(let i=0; i<myMap[bucket].length; i++) {
        if(myMap[bucket][i][0] === key){
            myMap[bucket][i][1] = value
            return
        }
    }
    
    myMap[bucket].push([key, value])
};

/** 
 * @param {number} key
 * @return {number}
 */
MyHashMap.prototype.get = function(key) {
    let bucket = key % sz
    for(let i=0; i<myMap[bucket].length; i++) {
        if(myMap[bucket][i][0] === key) return myMap[bucket][i][1]
    }
    return -1
};

/** 
 * @param {number} key
 * @return {void}
 */
MyHashMap.prototype.remove = function(key) {
    let bucket = key % sz
    for(let i=0; i<myMap[bucket].length; i++) {
        if(myMap[bucket][i][0] === key) {
            myMap[bucket][i] = myMap[bucket][myMap[bucket].length-1]
            myMap[bucket].pop()
        }
    }
};

/** 
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */