class Solution {
public:
    int dp[1000][11];
    int solve(vector<int>&job, int ind , int day){
        if(ind==job.size()){
            return day == 0 ? 0 : INT_MAX;
        }
        
        if(day<0) return INT_MAX;
        if(dp[ind][day]!=-1) return dp[ind][day];
        
        
        int mx = 0, poss=INT_MAX;
        for(int i=ind; i<job.size(); i++){
            mx = max(job[i], mx);
            int may = solve(job, i+1, day-1);
            if(may!=INT_MAX){
                poss = min(poss, mx+may);
            }
        }
        
        return dp[ind][day]=poss;
    }
    int minDifficulty(vector<int>& job, int d) {
        int N = job.size();
        memset(dp, -1, sizeof(dp));
        int ans= solve(job, 0, d);
        return ans!=INT_MAX ? ans : -1;
    }
};