#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&arr, int val){
    arr.push_back(val);

    for(int i=arr.size()-1; i>=1; i--){
        if(arr[i]>arr[i-1]){
            break;
        }
        swap(arr[i], arr[i-1]);
    }
}
int main(){
    int N;
    cin >> N;

    vector<int> arr;

    while(N--){
        int val;
        cin >> val;

        insertionSort(arr, val);

        for(int i : arr){
            cout << i << " ";
        }
        cout << endl;
    }

}

/*
TC : 
----
Best Case : O(N) // Array elements are comming in sorted way
Worst Case : O(N^2) // Array sorted in reverse order
Avg Case : O(N^2) // Array in random order

Use Cases
--------
query related problems. ex find meian with updating values reqularly 
*/