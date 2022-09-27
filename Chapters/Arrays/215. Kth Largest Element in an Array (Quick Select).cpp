class Solution {
public:
    int quickSelect(vector<int>&arr, int low, int high, int k){
        if(low>high)
            return -1;

        int pivot = high;

        int j = low -1;

        for(int i=low; i<=high; i++)
            if(arr[i]<=arr[high])
                swap(arr[++j], arr[i]);
        
        if(j==k)
            return arr[j];
        else if(k<j)
            return quickSelect(arr, low, j-1, k);
        else 
            return quickSelect(arr, j+1, high, k);    
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }
};