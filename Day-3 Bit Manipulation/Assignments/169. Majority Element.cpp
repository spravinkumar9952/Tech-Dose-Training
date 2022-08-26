class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max = nums[0], ctr = 1;
        
        for(int i=1; i<nums.size(); i++){
            if(max == nums[i]) ctr++;
            else ctr--;
            
            if(ctr<0){
                max = nums[i];
                ctr = 0;
            }
        }
        return max;
    }
};
