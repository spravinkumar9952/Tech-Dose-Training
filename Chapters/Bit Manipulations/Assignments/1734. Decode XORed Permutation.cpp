class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        // 1^2^3... ^N
        // a1^a2 , a2^a3 , a3^a4... an-1 ^ an
        // 
        
        int natXor = 0, N = encoded.size();
        for(int i=1; i<=N+1; i++)
            natXor ^= i;
        
        int enXor = 0;
        for(int i=1; i<N; i+=2)
            enXor ^= encoded[i];
        
        vector<int> ans(N+1);
        ans[0] = natXor ^ enXor;
        
        for(int i=0; i<N; i++)
            ans[i+1] = ans[i]^encoded[i];
        
        return ans;   
    }
};