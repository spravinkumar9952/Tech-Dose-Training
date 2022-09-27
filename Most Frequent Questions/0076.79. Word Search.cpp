Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?


class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int os[5] = {1, 0, -1, 0, 1};
    int R, C; 
    bool solve(vector<vector<char>>& board, string &word, int ind, int r, int c, vector<vector<bool>>& vis){
        
        if(ind==word.size()) 
            return true;
        if(r<0 || c<0 || r>=R || c>=C || word[ind]!=board[r][c] || vis[r][c]) 
            return false;
        
        vis[r][c] = true;
        
        for(int o = 0; o < 4; ++o){
            int sr = r+os[o], sc = c + os[o + 1];
            if(solve(board, word, ind+1, sr, sc, vis)){
                vis[r][c] = false;
                return true;
            }
        }
        vis[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        R = board.size(), C = board[0].size();
        
         vector<vector<bool>> vis(R, vector<bool>(C, false));
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(solve(board, word, 0, i, j, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};