
// TC : O(NlogK)
// SC : O(K)
// TC : O(N) --> https://leetcode.com/problems/k-closest-points-to-origin/discuss/220235/Java-Three-solutions-to-this-classical-K-th-problem.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        int N = points.size();
        priority_queue<vector<int>> pq;
        
        for(auto i : points){
            int dist = i[0]*i[0]+i[1]*i[1];
            pq.push({dist, i[0], i[1]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            vector<int> curr = pq.top(); pq.pop();
            ans.push_back({curr[1], curr[2]});
        }
        return ans;
    }
};