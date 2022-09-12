class Solution {
public:
    // TC : O(NlogN)
    // SC : O(1) (ans not included)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0], end = intervals[0][1];
        for(auto i : intervals){
            if(i[0]<=end){
                end = max(end, i[1]) ;
            }else{
                ans.push_back({start, end});
                start = i[0], end = i[1];
            }
        }
        
        ans.push_back({start, end});
        return ans;
    }
};