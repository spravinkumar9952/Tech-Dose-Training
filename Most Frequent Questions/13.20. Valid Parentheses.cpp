class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char i: s){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
            }
            else{
                if(st.empty())
                    return false;
                if(!(st.top()=='(' && i==')' || st.top()=='{' && i=='}' || st.top()=='[' && i==']'))
                    return false;
                st.pop();
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};