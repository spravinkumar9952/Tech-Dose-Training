// TC : O(N)
// SC : O(N)
class Solution {
public:
    vector<int> dp;
    int solve(string&s, int ind){
        if(ind==s.size()) return 1;
        
        if(dp[ind]!=-1) return dp[ind];
        
        char curr = s[ind];
        int poss = 0;
        
        if(s[ind]<='9' && s[ind]>='1'){
            poss = solve(s, ind+1);
        }
        if(s[ind]=='1' && ind<s.size()-1){
            if(s[ind+1]>='0' && s[ind+1]<='9'){
                poss +=solve(s, ind+2);
            }
        }
        if(s[ind]=='2' && ind<s.size()-1){
            if(s[ind+1]>='0' && s[ind+1]<='6'){
                poss += solve(s, ind+2);
            }
        }
        return dp[ind] = poss;
    }
    int numDecodings(string s) {
        int N = s.size();
        dp.resize(N, -1);
        return solve(s, 0);
    }
};