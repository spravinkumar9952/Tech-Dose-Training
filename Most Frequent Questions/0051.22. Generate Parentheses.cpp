Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8


class Solution {
public:
    vector<string> ans;
    void g(string& s, int op, int cl, int n, int ind){
        if(cl>op || op>n/2) return ;
        if(n==ind){
            ans.push_back(s);
            return ;
        }
        s[ind]='(';
        g(s, op+1, cl, n, ind+1);
        s[ind]=')';
        g(s, op, cl+1, n, ind+1);
    }
    vector<string> generateParenthesis(int n) {
        string s=string(2*n, ')');
        g(s, 0, 0, 2*n, 0);
        return ans;
    }
};