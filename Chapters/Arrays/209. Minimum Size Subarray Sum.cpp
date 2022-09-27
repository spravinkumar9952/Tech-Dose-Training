class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0, N = nums.size(), ans = INT_MAX, sum = 0;
        
        for(int i=0; i<N; i++){
            sum += nums[i];
            
            while(j<=i && sum-nums[j] >= target){
                sum -= nums[j++];
            }
            
            if(sum >= target){
                ans = min(ans,i-j+1);
            }
        }
        return ans%INT_MAX;
    }
};