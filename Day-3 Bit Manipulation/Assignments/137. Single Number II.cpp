// TC : O (Nlog(N))
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N = nums.size();
        
        int ans = 0;
        
        for(int i=0; i<=31; i++){
            int ctr = 0;
            // count bits
            for(int j : nums){
                if(j&(1<<i)){
                    ctr++;
                }
            }
            // if its not divisible by 3, then that extra bit belongs to the single number 
            if(ctr%3) ans |= 1<<i;
        }
        return ans;
    }
};