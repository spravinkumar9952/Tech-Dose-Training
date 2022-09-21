Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.


class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int ans=0, R = mat.size(), C = mat[0].size();
        vector<vector<int>> dp(R+1, vector<int>(C+1));
        for(int i=1; i<=mat.size(); i++){
            for(int j=1; j<=mat[0].size(); j++){
                if(mat[i-1][j-1]-'0'){
                    dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]})+1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};