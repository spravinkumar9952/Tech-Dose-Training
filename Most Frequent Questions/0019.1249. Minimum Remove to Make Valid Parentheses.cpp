
// TC : O(N)
// SC : O(N)
// SC : O(1) and diff methods ---> https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/1850228/Java-4-Solutions-with-slight-optimisations

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        // remove invalid )
        string medAns = "", ans="";
        int rank = 0;
        for(char c : s){
            if(!isalpha(c)){
                if(c=='(') rank++;
                else rank--;
            }
            if(rank<0){
                rank++;
                continue;
            }
            medAns+=c;
        }
        
        // remove Invalid ( 
        reverse(medAns.begin(), medAns.end());
        rank = 0;
        for(char c : medAns){
            if(!isalpha(c)){
                if(c==')') rank++;
                else rank--;
            }
            if(rank<0){
                rank++;
                continue;
            }
            ans+=c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};