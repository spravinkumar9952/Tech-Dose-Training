class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        vector<int> leftMax(N), rightMax(N);
        
        int mx = 0;
        for(int i=N-1; i>=0; i--){
            rightMax[i] = mx;
            mx = max(mx, height[i]);
        }
        
        mx = 0;
        for(int i=0; i<N; i++){
            leftMax[i] = mx;
            mx = max(mx, height[i]);
        }
        
        int ans = 0;
        for(int i=0; i<N; i++){
            ans += max(0, min(leftMax[i], rightMax[i])-height[i]);
        }
        return ans;
    }
};