class Solution {
public:
    int compress(vector<char>& chars) {
        int ind = 0, ans = 0, arrInd =0;
        while(ind<chars.size()){
            char key = chars[ind];
            int ctr = 0;
            while(ind<chars.size() && key == chars[ind]){
                ind++;
                ctr++;
            }
            if(ctr<=1) chars[arrInd++]=key;
            else {
                chars[arrInd++] = key;
                for(char c: to_string(ctr)){
                    chars[arrInd++] = c;
                }
            }
        }
        return arrInd;
    }
};