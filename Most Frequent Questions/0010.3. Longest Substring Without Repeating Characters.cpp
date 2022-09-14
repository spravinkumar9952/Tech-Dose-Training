class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans= 0, j=-1;
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end()){
                j = max(j, mp[s[i]]);
            }
            mp[s[i]] = i;
            ans = max(ans, i-j);
        }
        return ans ;
    }
};