class Solution {
public:
    bool g(string &s, int pass){
        for(int i=0, j=s.size()-1; i<=j; i++, j--){
            if(i==pass)i++;
            if(j==pass) j--;
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l =0, h= s.size()-1;
        
        while(l<=h){
            if(s[l]!=s[h]){
                return g(s, l) || g(s, h);
            }
            l++, h--;
        }
        return true;
    }
};