class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0, N = nums.size(), high = N-1, start = 0;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]<nums[start]) start = mid;
            if(nums[mid]>=nums[high]){
                low = mid+1;
            }else{
                
                high = mid-1;
            }
        }

        low = 0, high = N-1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            int rotPos = (mid+start)%N;
            if(nums[rotPos]==target) return rotPos;
            else if(nums[rotPos]<target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};  