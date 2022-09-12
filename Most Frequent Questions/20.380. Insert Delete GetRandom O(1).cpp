class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    // TC : O(1)
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        nums.push_back(val);
        mp[val] = nums.size()-1;
        return true;
    }
    // TC : O(1)
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        
        int pos = mp[val];
        int last = nums.size()-1;
        
        swap(nums[pos], nums[last]);
        mp[nums[pos]] = pos;
        
        mp.erase(val);
        nums.pop_back();
        
        return true;
    }
    // TC : O(1)
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */