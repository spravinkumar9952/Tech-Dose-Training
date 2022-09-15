class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> words, vis;
        queue<string> q;
        
        q.push(beginWord);
        vis.insert(beginWord);
        int ans=0;
        
        for(string i : wordList) words.insert(i);
        
        while(q.empty()==false){
            int sz = q.size();
            ans++;
            while(sz--){
                string curr = q.front(); q.pop();
                
                if(curr==endWord){
                    return ans;
                }
                
                for(int i=0; i<curr.size(); i++){
                    char currChar = curr[i];
                    for(char c='a'; c<='z'; c++){
                        curr[i] = c;
                        if(c!=currChar && words.count(curr) && !vis.count(curr)){
                            q.push(curr);
                            vis.insert(curr);
                        }
                    }
                    curr[i] = currChar;
                }
            }
        }
        return 0;
    }
};