class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind = m+n-1;
        m--, n--;
        while(m>=0 || n>=0){
            int a = m>=0 ? nums1[m] : INT_MIN;
            int b = n>=0 ? nums2[n] : INT_MIN;
            
            if(a>=b){
                nums1[ind--] = a;
                m--;
            }else{
                nums1[ind--] = b;
                n--;
            }
        }
    }
};