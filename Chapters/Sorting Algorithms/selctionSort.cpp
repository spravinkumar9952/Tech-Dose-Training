#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int>& arr){
    for(int i=0; i<arr.size()-1; i++){
        int minInd = i;
        for(int j = i+1; j<arr.size(); j++){
            if(arr[minInd]>arr[j]){
                minInd = j;
            }
        }
        swap(arr[minInd], arr[i]);
    }
}
int main(){
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int &i : arr)
        cin >> i;

    selectionSort(arr);

    for(int i : arr)
        cout << i << " ";
}


/*
Time Complexity 
-----------------
Best Case : O(N^2)
Worst Case : O(N^2)
Average Case : O(N^2)

So not depend on nature of the input
*/