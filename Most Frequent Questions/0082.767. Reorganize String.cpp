class Solution {
public:
    string reorganizeString(string s) {
        int N = s.size();
        
        vector<int> mp(26);
        for(char c : s){
            mp[c-'a']++;
        }
        
        char pre = ' ';
        for(int i=0; i<N; i++){
            int mx = 0, pos = -1;
            for(int j=0; j<26; j++){
                if(pre-'a'!=j && mp[j]>mx){
                    mx = mp[j];
                    pos = j;
                }
            }
            if(pos==-1) return "";
            mp[pos]--;
            s[i] = pos+'a';
            pre = pos+'a';
        }
        return s;
    }
};