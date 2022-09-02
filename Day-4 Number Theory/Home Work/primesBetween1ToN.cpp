#include <bits/stdc++.h>
using namespace std;

// TC : O(N*log(log(N)))
vector<int> getAllPrimeNumbers(int N){
    vector<int> primes;
    vector<bool> isPrime(N+1, true);

    for(int i=2; i*i<=N; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=N; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

int main(){
    int N;
    cin >> N;
    
    for(int i : getAllPrimeNumbers(N)){
        cout << i << " ";
    }
    return 0;
}