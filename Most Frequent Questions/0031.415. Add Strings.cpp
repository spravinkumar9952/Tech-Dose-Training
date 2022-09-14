class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string ans="";
        for(int i=num1.size()-1, j = num2.size()-1; i>=0 || j>=0; i--,j--){
            int a = i>=0 ? num1[i]-'0' : 0;
            int b = j>=0 ? num2[j]-'0' : 0;
            
            int sum = (a+b+carry)%10;
            ans += to_string(sum);
            carry = (a+b+carry)/10;
        }
        if(carry) ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};