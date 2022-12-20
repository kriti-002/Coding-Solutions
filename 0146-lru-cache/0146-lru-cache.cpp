class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>> :: iterator>mp;
    int maxSize;
    
    LRUCache(int capacity) {
        maxSize=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!= mp.end()){
            int val= (*mp[key]).second;
            //value became most recently used 
            cache.erase(mp[key]);
            cache.push_front({key, val});
            mp[key]=cache.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!= mp.end()){
            cache.erase(mp[key]);
            cache.push_front({key, value});
            mp[key]=cache.begin(); 
        }else{
            cache.push_front({key, value});
            mp[key]= cache.begin();
            if(mp.size() > maxSize) {
                // erase the last element of the cache from map
                mp.erase(cache.back().first);
                // pop that element from cache as well
                cache.pop_back();
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */