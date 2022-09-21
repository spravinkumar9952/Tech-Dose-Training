Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.


class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans="";
        int mn = INT_MAX;
        for(string i : str){
            int len = i.size();
            mn = min(mn, len);
        } 
        for(int i=0; i<mn; i++){
            for(string j : str){
                if(j[i]!=str[0][i]) return ans;
            }
            ans+=str[0][i];
        }
        return ans;
    }
};