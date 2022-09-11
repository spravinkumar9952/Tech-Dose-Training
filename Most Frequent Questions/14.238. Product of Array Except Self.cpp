class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N);
        
        int zero = 0, mul=1;
        for(int i : nums){
            zero += !i;
            if(i) mul*=i;
        }
        
        if(zero>=2) return ans;
        
        for(int i=0; i<N; i++){
            if(zero){
                if(!nums[i]) ans[i] = mul;
            }else{
                ans[i] = mul/nums[i];
            }
        }
        return ans;
    }
};