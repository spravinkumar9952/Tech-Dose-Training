Given an m x n matrix, return all elements of the matrix in spiral order

class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        vector<int> ans(R*C);
        int ind = 0, end = R&1 ? R/2 : (R-1)/2;
        
        for(int i=0; i<=end; i++){
            
            for(int j=i; j<=C-1-i && ind<R*C; j++) ans[ind++] = matrix[i][j];
            
            for(int j=i+1; j<=R-1-i && ind<R*C; j++) ans[ind++] = matrix[j][C-1-i];
            
            for(int j=C-2-i; j>=i && ind<R*C; j--) ans[ind++] = matrix[R-1-i][j];
            
            for(int j=R-2-i; j>i && ind<R*C; j--) ans[ind++] = matrix[j][i];
        }
        return ans;
    }
};