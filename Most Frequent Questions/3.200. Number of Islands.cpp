class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size(), ans = 0;
        vector<vector<int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(grid[i][j]=='1'){
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] ='0';
                    ans++;
                    while(!q.empty()){
                        auto [r, c] = q.front(); q.pop();
                        for(vector<int> i : dir){
                            int sr = r+i[0], sc = c+i[1];
                            if(sr<0 || sc<0 || sr>=R || sc>=C || grid[sr][sc]=='0') continue;
                            grid[sr][sc] = '0';
                            q.push({sr,sc});
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};