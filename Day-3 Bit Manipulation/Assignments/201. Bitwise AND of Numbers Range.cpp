class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int diff = right - left;
        int ans = left & right;
        
        for(int i=0; i<=30; i++){
            if(diff/(1<<i)){
                ans &= ~(1<<i);
            }
        }
        
        return ans;
    }
};