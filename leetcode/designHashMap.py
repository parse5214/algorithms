class MyHashMap:
    
    myMap = []
    sz = 769

    def __init__(self):
        self.myMap = self.sz*[None]

        
    def put(self, key: int, value: int) -> None:
        bucket = key % self.sz
        
        if(self.myMap[bucket] == None):
            self.myMap[bucket] = [[key, value]]
            return
        
        for i in range(0, len(self.myMap[bucket])):
            if(self.myMap[bucket][i][0] == key):
                self.myMap[bucket][i][1] = value
                return
        
        self.myMap[bucket].append([key, value])
        

    def get(self, key: int) -> int:
        bucket = key % self.sz
        
        if(self.myMap[bucket] == None): return -1
        
        for i in range(0, len(self.myMap[bucket])):
            if(self.myMap[bucket][i][0] == key): return self.myMap[bucket][i][1]
        
        return -1
    

    def remove(self, key: int) -> None:
        bucket = key % self.sz
        
        if(self.myMap[bucket] == None): return
        for i in range(0, len(self.myMap[bucket])):
            if(self.myMap[bucket][i][0] == key):
                self.myMap[bucket].pop(i)
                return


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)