
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9']



class Solution {
public:
    vector<string> ans;
    vector<string> mp={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void g(string dit, string tmp, int ind){
        if(ind==dit.size()){
            ans.push_back(tmp);
            return ;
        }
        for(char c : mp[dit[ind]-'0']){
            tmp+=c;
            g(dit, tmp, ind+1);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        g(digits, "", 0);
        if(ans[0]=="") ans.pop_back();
        return ans;
    }
};