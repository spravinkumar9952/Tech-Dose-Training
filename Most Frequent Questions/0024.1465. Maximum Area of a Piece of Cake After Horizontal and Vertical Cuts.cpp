class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        long long mxH=0, mxV=0;
        H.push_back(0);
        H.push_back(h);
        V.push_back(0);
        V.push_back(w);
        sort(H.begin(), H.end());
        sort(V.begin(), V.end());
        for(int i=1; i<H.size(); i++){
            mxH = max(mxH, (long long)H[i]-H[i-1]);
        }
        for(int i=1; i<V.size(); i++){
            mxV = max(mxV, (long long)V[i]-V[i-1]);
        }
        long long mod = 1e9+7;
        return ((mxH%mod)*(mxV%mod))%mod;
    }
};