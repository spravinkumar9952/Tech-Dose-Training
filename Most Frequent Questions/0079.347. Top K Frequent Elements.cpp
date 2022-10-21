class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        auto cmp = [](auto a, auto b){
            return a[0] > b[0];  
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for(int i : nums){
            mp[i]++;
        }
        
        for(auto &[key, val] : mp){
             pq.push({val, key});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        
        while(pq.empty()==false){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;
    }
};