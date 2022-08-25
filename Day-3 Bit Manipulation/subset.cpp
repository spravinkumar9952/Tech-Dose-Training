#include <bits/stdc++.h>
using namespace std;

// TC : O(2^N)
// SC : O(2^N)

vector<vector<int>> getSubsets(int N, vector<int>&arr){
    vector<vector<int>> subsets;

    // Generate all possible masks 
    for(int i=0; i<(1<<N); i++){
        vector<int> currSet ;

        // iterate through mask
        for(int j=0; j<N; j++){

            // if is set bit then include th jth element to set
            if((i&(1<<j)) != 0){
                currSet.push_back(arr[j]);
            }
        }
        subsets.push_back(currSet);
    }

    return subsets;
}

int main(){
    
    int N; 
    cin >> N;
    
    vector<int> arr(N);
    for(int &i : arr)
        cin >> i;

    vector<vector<int>> subsets = getSubsets(N, arr);

    for(vector<int> &i : subsets){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}