class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = -1, high = nums.size();
        
        for(int i=0; i<nums.size(); ){
            if(nums[i]==0 && low < i){
                swap(nums[++low], nums[i]);
            }
            else if(nums[i]==2 && high > i){
                swap(nums[--high], nums[i]);
            }else{
                i++;
            }
        }
        
    }
};