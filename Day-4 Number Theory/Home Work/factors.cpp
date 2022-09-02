#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
vector<int> getFactors1(int val){
    vector<int> factors;
    for(int i=1; i<=val; i++){
        if(val%i==0){
            factors.push_back(i);
        }
    }
    return factors;
}

// TC : O(root(N))
vector<int> getFactors2(int val){
    vector<int> factors;
    for(int i=1; i*i<=val; i++){
        if(val%i==0){
            factors.push_back(i);
            if(val/i != i){
                factors.push_back(val/i);
            }
        }
    }
    return factors;
}

int main(){
    int N;
    cin >> N;


    for(int i : getFactors1(N)){
        cout << i << " ";
    }
    cout << endl;
    for(int i : getFactors2(N)){
        cout <<  i << " ";
    }
}