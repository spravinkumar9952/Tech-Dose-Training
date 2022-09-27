class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxProfit(vector<int>& prices) {
        int ans = 0, N = prices.size(), mx = 0;
        
        for(int i=N-1; i>=0; i--){
            ans = max(ans, mx-prices[i]);
            mx = max(mx, prices[i]);
        }
        return ans;
    }
};