class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int ind = 0, N = words.size();
        vector<string> ans;
        
        while(ind<N){
            vector<string> arr;
            int len = 0;
            while(ind<N && len + arr.size()+words[ind].size() <= maxWidth){
                arr.push_back(words[ind]);
                len += words[ind++].size();
            }
            int space = maxWidth - len;
            int sz = arr.size();
            int eachSpace = space / max(1, sz-1);
            int extraSpace = space % max(1, sz-1);
            
            if(ind==words.size()) eachSpace = 1, extraSpace = 0;
            
            string line = "";
            for(int i=0; i<arr.size()-1; i++){
                line += arr[i] + string(eachSpace, ' ');
                if(extraSpace){
                    line += " ";
                    extraSpace--;
                }
            }
            line += arr.back();
            line += string(maxWidth-line.size(), ' ');
            ans.push_back(line);
        }
        return ans;
    }
};