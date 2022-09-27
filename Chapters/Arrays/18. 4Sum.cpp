class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int N= nums.size();

        vector<vector<int>> ans;
        #define int long long 
        for(int i=0; i<N; ){
            for(int j=i+1; j<N; ){
                int sum = nums[i]+nums[j];
                int l = j+1, h= N-1;
                while(l < h){
                    int newSum = sum + nums[l] + nums[h];
                    if(newSum == target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[h]});
                        int key3 = nums[l], key4 = nums[h];
                        while(l < h && nums[l]==key3) l++;
                        while(l < h && nums[h]==key4) h--;
                    }else if(newSum > target){
                        h--;
                    }else{
                        l++;
                    }
                }
                int key2 = nums[j];
                while(j < N && nums[j]==key2) j++;
            }
            int key1 = nums[i];
            while(i < N && nums[i]==key1) i++;
        }

        
        #undef int 
        return ans;
    }
};