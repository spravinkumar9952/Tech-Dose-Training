class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char, int> mp;
        
        for(int i=0; i<order.size(); i++){
            mp[order[i]] = i;
        }
        
        for(int i=0; i<words.size()-1; i++){
            int len1 = words[i].size();
            int len2 = words[i+1].size();
            
            int len = min(len1, len2);
            
            for(int j=0; j<len; j++){
                if(mp[words[i][j]]<mp[words[i+1][j]]){
                   goto end;
                } 
                if(mp[words[i][j]]>mp[words[i+1][j]]){
                    return false;
                }
            }
            
            if(len1>len2) return false;
            end:;
            
        }
        
        return true;
    }
};