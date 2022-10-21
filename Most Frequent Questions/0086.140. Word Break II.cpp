class Solution {
public:
    struct Trie{
        vector<Trie*> child;
        bool isEnd = false;
        Trie(){
            child.resize(26, NULL);
            isEnd = false;
        }
    };
    
    Trie *root = new Trie();
    
    void build(string &s){
        Trie *temp = root;
        for(char c : s){
            if(temp->child[c-'a']==NULL)
                temp->child[c-'a'] = new Trie();
            temp = temp->child[c-'a'];
        }
        temp->isEnd = true;
    }
    
    vector<string> ans;
    
    void solve(string &s, int ind, string may){
        // cout << "***" <<endl;
        if(ind==s.size()){
            may.pop_back();
            ans.push_back(may);
        }
        
        Trie *temp = root;
        string str = "";
         
        for(int i=ind; i<s.size(); i++){
            int pos = s[i]-'a';
            if(!temp->child[pos]) return ;
            
            str+=s[i];
            // cout << str << endl;
            if(temp->child[pos]->isEnd){
                solve(s, i+1, may+str+" ");
            }
            
            temp = temp->child[pos];
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &i : wordDict)
            build(i);
        
        solve(s, 0, "");
        return ans;
    }
};