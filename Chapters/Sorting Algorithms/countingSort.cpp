#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr){
    int mx = *max_element(arr.begin(), arr.end());

    vector<int> frq(mx+1), ans(arr.size());

    for(int i : arr)
        frq[i]++;

    for(int i=1; i<=mx; i++)
        frq[i] += frq[i-1];

    for(int i=arr.size()-1; i>=0; i--)
        ans[--frq[arr[i]]] = arr[i];
    
    arr = ans;
}

int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int &i :arr)
        cin >> i;

    countingSort(arr);

    for(int i : arr)
        cout << i << " ";
}