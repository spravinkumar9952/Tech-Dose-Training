class Solution {
public:
    // TC : O(log10)
    // Simple & Interesting sol --> https://leetcode.com/problems/reverse-integer/discuss/4060/My-accepted-15-lines-of-code-for-Java
    int reverse(int x) {
        int ans = 0;
        while(x){
            if((x>0 && INT_MAX/10<ans) || (x<0 && INT_MIN/10>ans)){
                return 0;
            }
            
            ans = ans*10+(x%10);
            x/=10;
        }
        return ans;
    }
};