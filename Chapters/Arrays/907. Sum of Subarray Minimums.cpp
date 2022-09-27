Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104


class Solution {
public:
   
    int sumSubarrayMins(vector<int>& arr) {
        #define ll long long
        ll mod = 1e9+7, ans=0, N = arr.size();
        vector<ll> left(N), right(N);
        stack<int> st;
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                right[st.top()] = i-st.top()-1;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) right[st.top()] = N-1-st.top(), st.pop();
        
        for(int i=N-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                left[st.top()] = st.top()-i-1;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) left[st.top()] = st.top(), st.pop();
        
        for(int i=0; i<N; i++){
            //cout <<i << " "<< left[i] << " " << right[i] << endl;
            ll val = arr[i];
            ans=(ans+((left[i]+1LL)*(right[i]+1)*val)%mod)%mod;
        }
        return ans;
    }
};