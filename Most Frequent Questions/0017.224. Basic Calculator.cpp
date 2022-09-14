class Solution {
public:
    
    int calculate(string s) {
        vector<string> arr;
        
        int ind = 0;
        while(ind<s.size()){
            string curr ;
            curr +=s[ind++];
            if(curr==" "){
                continue;
            }
            if(curr=="+" || curr=="-" || curr=="(" || curr==")"){
                arr.push_back(curr);
            }else if(isdigit(curr[0])){
                while(ind<s.size() && isdigit(s[ind])){
                    curr += s[ind++];
                }
                arr.push_back(curr);
            }
        }
        stack<int> st;
        int res = 0, mul = 1;
        for(string i : arr) {
            if(isdigit(i[0])){
                res += mul*stoi(i);
            }else if(i=="("){
                st.push(res);
                st.push(mul);
                res = 0;
                mul=1;
            }else if(i==")"){
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }else if(i=="-"){
                mul = -1;
            }else if(i=="+"){
                mul = 1;
            }
        }
        return res;
    }
};