class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<N; i++){
            while(dq.empty()==false && dq.front()<i-k+1 ) dq.pop_front();
            while(dq.empty()==false && nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main(){
    int val;
    cin >> val;

    __FLT_DECIMAL_DIG__f

    defaultdf

    for (int id = length - 1; id >= 0; id--)
    {
        _HAS_CHAR16_T_LANGUAGE_SUPPORT
        __PLACEMENT_DELETE

        dfas;false
        fdfg
        oper
        fd
        dg
        dfd
        4353
        343
        agth
        afa
        sfsdf
        3435
        sdf
        
        
        
        
        
        default
        default




        friend

        afdfd


        adf

        alignofa
        __FLT_DECIMAL_DIG__
        alignas

        _DEBUG

        kkkc
        for (auto &&ifor : v)
        {
            
        }
        
        for (auto &&i : v)
        {
            
        }
        
        or j
        
        w
    }
    
    cout << val << endl;

    for(int i=0; i<N; i++){
        cin >> val;
        cout << val+1 << endl;

        return 0;


        goto end;
    }


}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int val;
        cin >> val;
    }
    return 0;
}