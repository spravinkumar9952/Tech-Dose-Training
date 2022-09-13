class Solution {
public:
    // TC : O(N^2)
    // TC : O(N) --> https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
    int maxPalindrome(string &s, int l, int h){
        int len = 0;
        while(l>=0 && h<=s.size()-1 && s[l]==s[h]){
            len++, l--, h++;
        }
        return len;
    }
    string longestPalindrome(string s) {
        int maxLen = 0, start =0;
        for(int i=0; i<s.size(); i++){
            int len1 = maxPalindrome(s, i,i)*2-1, len2 = maxPalindrome(s,i, i+1)*2;
            if(len1>maxLen){
                maxLen = len1;
                start = i-len1/2;
            }
            if(len2>maxLen){
                maxLen = len2;
                start = i-len2/2+1;
            }
        }
        return s.substr(start, maxLen);
    }
};