#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high){
    int i = low, j= mid+1;

    vector<int> mergeArr;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            mergeArr.push_back(arr[i++]);
        }else{
            mergeArr.push_back(arr[j++]);
        }
    }
    while(i<=mid) mergeArr.push_back(arr[i++]);
    while(j<=high) mergeArr.push_back(arr[j++]);

    for(int k=low; k<=high; k++){
        arr[k] = mergeArr[k-low];
    }
}
void mergeSort(vector<int>&arr, int low, int high){
    if(low==high){
        return ;
    }

    int mid = low + (high-low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int &i : arr){
        cin >> i;
    }

    mergeSort(arr, 0, arr.size()-1);

    for(int i : arr){
        cout << i << " ";
    }
}


/*
TC :
Best : O(Nlog(N))
Worst : O(Nlog(N))
Avg : O(Nlog(N))

SC : O(Nlog(N))
Not depend on input nature
*/