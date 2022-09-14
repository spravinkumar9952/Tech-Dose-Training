T// TC : ~O(1) or O(log10)

class Solution {
public:
    vector<string> above20 = {"","Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                    "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string solve(int num){
        if(num >= 1e9) return solve(num/int(1e9)) +" Billion "+solve(num % int(1e9));
        if(num >= 1e6) return solve(num/int(1e6)) +" Million "+solve(num % int(1e6));
        if(num >= 1e3) return solve(num/int(1e3)) +" Thousand "+solve(num % int(1e3));
        if(num >= 1e2) return solve(num/int(1e2)) +" Hundred "+solve(num % int(1e2));
        if(num >= 20)  return above20[num/10] + " " + solve(num % 10);
        return below20[num];
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        
        string str = solve(num), ans ="";
        char last = '*';
        for(char c : str){
            if(last == c && c==' '){
                continue;
            }
            last = c;
            ans += c;
        }
        while(ans.back()==' ') ans.pop_back();
        return ans;
    }
    
    
};