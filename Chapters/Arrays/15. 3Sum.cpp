class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int N =nums.size(), pre=INT_MIN;
        for(int i=0; i<N; i++){
            if(pre!=nums[i]){
                int l = i+1, h = N-1;
                while(l<h){
                    if(nums[l]+nums[h]+nums[i]==0){
                        ans.push_back({nums[i], nums[l], nums[h]});
                        int key1 = nums[l], key2 = nums[h];
                        while(nums[l]==key1 && l<h) l++;
                        while(nums[h]==key2 && l<h) h--;
                    }else if(nums[l]+nums[h]+nums[i]>0){
                        h--;
                    }else{
                        l++;
                    }
                }
                pre = nums[i];
            }
        }
        
        
        return ans;
    }
};