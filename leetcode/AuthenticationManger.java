class AuthenticationManager {
    
    class Pair implements Comparable<Pair> {
        int time = 0;
        String id = "";
        
        public Pair(int time, String id) {
            this.time = time;
            this.id = id;
        }
        
        @Override
        public int compareTo(Pair b) {
            if(this.time > b.time) return 1;
            else if(this.time < b.time) return -1;
            else return 0;
        }
        
        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Pair pa = (Pair) o;
            return time == pa.time && id.equals(pa.id);
        }
        
        @Override
        public int hashCode() {
            int hash = 1;
            int prime = 31;
            hash = prime*hash + time;
            hash = prime*hash + ((id == null)? 0 : id.hashCode());
            return hash;
        }
    }
    
    int timeToLive = 0;
    Map<String, Integer> myMap = new HashMap<>();
    TreeSet<Pair> mySet = new TreeSet<>();
        
    public AuthenticationManager(int timeToLive) {
        this.timeToLive = timeToLive;
    }
    
    public void generate(String tokenId, int currentTime) {
        myMap.put(tokenId, currentTime + timeToLive);
        mySet.add(new Pair(myMap.get(tokenId), tokenId));
    }
    
    public void renew(String tokenId, int currentTime) {
        countUnexpiredTokens(currentTime);
        if(!myMap.containsKey(tokenId)) return;
        mySet.remove(new Pair(myMap.get(tokenId), tokenId));
        myMap.remove(tokenId);
        myMap.put(tokenId, currentTime + timeToLive);
        mySet.add(new Pair(myMap.get(tokenId), tokenId));
    }
    
    public int countUnexpiredTokens(int currentTime) {
        while(!mySet.isEmpty() && (mySet.first().time <= currentTime)) {
            myMap.remove(mySet.first().id);
            mySet.pollFirst();
        }
        return myMap.size();
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */