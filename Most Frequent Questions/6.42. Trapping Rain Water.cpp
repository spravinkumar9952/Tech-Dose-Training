class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    // SC : O(1) --> https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c++-code:-O(n)-time-O(1)-space
    // Official Sol --> https://leetcode.com/problems/trapping-rain-water/solution/
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