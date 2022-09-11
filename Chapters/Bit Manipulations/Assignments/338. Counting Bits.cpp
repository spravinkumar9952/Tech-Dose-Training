class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        for(int i=1; i<=n; i<<=1){
            for(int j=0; j<i; j++){
                dp[i+j] += dp[j]+1;
                if(j+i==n) return dp;
            }
        }
        return dp;
    }
};