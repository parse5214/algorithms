class AuthenticationManager {
public:
    int timeToLive = 0;
    unordered_map<string, int> myMap;
    set<pair<int, string>> mySet;
    
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        myMap[tokenId] = currentTime + timeToLive;
        mySet.insert({myMap[tokenId], tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        countUnexpiredTokens(currentTime);
        if(!myMap.count(tokenId)) return;
        mySet.erase({myMap[tokenId], tokenId});
        myMap[tokenId] = currentTime + timeToLive;
        mySet.insert({myMap[tokenId], tokenId});
    }
    
    int countUnexpiredTokens(int currentTime) {
        while(!mySet.empty() && (*mySet.begin()).first <= currentTime) {
            myMap.erase((*mySet.begin()).second);
            mySet.erase(mySet.begin());
        }
        return myMap.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */