class LRUCache {
public:
    list<pair<int, int>> arr;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int cap ;
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it==mp.end()) return -1;
        
        arr.splice(arr.begin(), arr, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it==mp.end()){
            arr.emplace_front(key, value);
            mp[key] = arr.begin();
            
            if(mp.size()>cap){
                mp.erase(arr.back().first);
                arr.pop_back();
            }
        }else{
            arr.splice(arr.begin(), arr, mp[key]);
            it->second->second = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */