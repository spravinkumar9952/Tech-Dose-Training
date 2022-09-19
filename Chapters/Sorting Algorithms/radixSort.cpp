#include <bits/stdc++.h>
using namespace std;

int getLenByBase(int val, int base){
    if(val==0) return 1;

    int len = 0;
    while(val){
        val/=base;
        len++;
    }
    return len;
}

int digitAtPos(int val, int base, int pos){
    return (int) ( val / pow(base, pos) ) % base;
}

void radixHelper(vector<int>&arr, int base, int len, int pos){
    if(pos == len) return ;

    vector<int> frq(base+1), ans(arr.size());

    for(int i : arr)
        frq[digitAtPos(i,base, pos)]++;

    for(int i=1; i<=base; i++)
        frq[i] += frq[i-1];

    for(int i=arr.size()-1; i>=0; i--)
        ans[--frq[digitAtPos(arr[i], base, pos)]] = arr[i];
    
    arr = ans;

    radixHelper(arr, base, len, pos+1);
}

void radixSort(vector<int>& arr, int base){
    int mx = *max_element(arr.begin(), arr.end());
    int len = getLenByBase(mx, base);

    radixHelper(arr, base, len, 0);
}

int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int &i : arr)
        cin >> i;
    
    // Higher base fast sorting but High space
    // Low base slow sorting but low space
    int base = 18;
    radixSort(arr, base);

    for(int i : arr)
        cout << i << " ";
}

// TC : O(base * log(MAX) by base )
// SC : O(Base) (without considering temp array & recursive calls)

// Best for large numbers . where we increase the base to reduce the time complexity