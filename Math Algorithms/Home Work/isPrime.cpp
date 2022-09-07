#include <bits/stdc++.h>

using namespace std;

// TC : O(N)
bool isPrime1(int val){
    for(int i=2; i<val; i++){
        if(val%i==0){
            return false;
        }
    }
    return true;
}

// TC : O(root(N))
bool isPrime2(int val){
    for(int i=2; i*i<=val; i++){
        if(val%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int N; 
    cin >> N;

    cout << (isPrime1(N) ? "Prime" : "Not Prime") << endl;
    cout << (isPrime2(N) ? "Prime" : "Not Prime") << endl;
}