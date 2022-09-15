class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i=0; i<nums.size(); i++){
            while(nums[i]>=1 && nums[i]<=N && nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        
        for(int i=0; i<N; i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return N+1;
    }
};