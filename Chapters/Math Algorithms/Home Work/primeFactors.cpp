#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int N){
    vector<int> primeFactors;

    for(int i=2; i*i<=N; i++){
        while(N%i==0){
            N/=i;
            primeFactors.push_back(i);
        }
    }
    if(N>1){
        primeFactors.push_back(N);
    }
    return primeFactors;
}

int main(){
    int N;
    cin >> N;

    for(int i : getPrimeFactors(N)){
        cout << i << " ";
    }
    return 0;
}