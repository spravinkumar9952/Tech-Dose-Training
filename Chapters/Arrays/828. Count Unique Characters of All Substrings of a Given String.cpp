class Solution {
public:
    // a
    // a b
    // a b c
    // b 
    // b c
    
    int uniqueLetterString(string s) {
        int N = s.size();
        
        unordered_map<char, int> mp;
        
        vector<int> left(N),right(N);
        
        int ans = 0;
        for(int i=0; i<N; i++){
            if(mp.find(s[i]) == mp.end()){
                left[i] = i+1;
            }else{
                left[i] = i-mp[s[i]];
            }
            mp[s[i]] = i;
        }
        mp.clear();
        for(int i=N-1; i>=0; i--){
            if(mp.find(s[i])==mp.end()){
                right[i] = N-i;
            }else{
                right[i] = mp[s[i]]-i;
            }
            mp[s[i]] = i;
        }
        for(int i=0; i<N; i++){
            ans += (right[i]*left[i]);
        }
        return ans;
    }
};