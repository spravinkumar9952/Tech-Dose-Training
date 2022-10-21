class Solution {
public:
    int dp[(int)1e4+1];
    int solve(vector<int>&arr, int amount){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        
        int poss = INT_MAX;
        for(int i : arr){
            if(amount-i>=0){
                poss = min(poss, solve(arr, amount-i));
            }
        }
        return dp[amount] = (poss!=INT_MAX ? poss+1 : INT_MAX);
    }
    int coinChange(vector<int>& arr, int amount) {
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(arr, amount);
        return ans==INT_MAX ? -1 :  ans ;
    }
};