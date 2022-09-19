#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int>&arr, int low, int high){
    if(low>=high)
        return ;

    int pivot = high;

    int j = low -1;

    for(int i=low; i<=high; i++)
        if(arr[i]<=arr[high])
            swap(arr[++j], arr[i]);

    quickSort(arr, low, j-1);
    quickSort(arr, j+1, high);    
}


int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int &i : arr)
        cin >> i;

    quickSort(arr, 0, arr.size()-1);

    for(int i : arr)
        cout << i << " ";
}

//  3 2 0 5 1
//j i       pivot
//  0 2 3 5 1
//  j   i   pivot
//  0 1 3 5 2
//    j     (i, pivot)
// [0] and [3, 5, 2]

// TC : Omega(O(NlogN)) when pivot is middle, Theta(NlogN), O(N^N) when array already sorted
// SC : O(1) without considering recursion stack
