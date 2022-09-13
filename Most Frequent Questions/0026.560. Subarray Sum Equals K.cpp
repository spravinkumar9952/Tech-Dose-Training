class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    
    // Sliding window will not work 
    //    --> Negative value
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int,int> mp;
        for(int i : nums){
            sum += i;
            mp[sum]++;
        }
        
        sum = 0;
        for(int i : nums){
            ans += mp[sum+k];
            sum+=i;
            mp[sum]--;
        }
        return ans;
    }
};