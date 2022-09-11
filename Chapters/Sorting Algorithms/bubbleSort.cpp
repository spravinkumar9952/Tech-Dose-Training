#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr){
    for(int i=0; i<arr.size()-1; i++){
        bool isSwap = false;
        for(int j=arr.size()-1; j>i; j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j], arr[j-1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            break;
        }
    }
}

int main(){
    int N; 
    cin >> N;

    vector<int> arr(N);
    for(int &i : arr){
        cin >> i;
    }

    bubbleSort(arr);

    for(int i : arr){
        cout << i << " ";
    }
}

/*
Time Complexity:
---------------
Worst Case : O(N^2) => Array already sorted in our revered codition
Best Case : O(N) => Array already sorted
Average Case : O(N^2) => Array elements arranged in random order
*/