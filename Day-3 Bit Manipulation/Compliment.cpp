#include <bits/stdc++.h>
using namespace std;

int _1sCompliment(int N){
    // just flip all bits
    return ~N;
}

int _1sComplimentMSB(int N){
    // manual toggle upto MSB
    for(int i=0; (N>>i) != 0; i++){
        N ^= 1 << i;
    }
    return N;
}

int _2sCompliment(int N){
    return (~N)+1;
}

int main(){
    int N; 
    cin >> N;

    // Toggle all the bit Not only MSB Length (1sCompliment)
    cout << _1sCompliment(N) << endl;

    // Toggle only until MSB
    cout << _1sComplimentMSB(N) << endl;

    // 2sCompliment 
    cout << _2sCompliment(N) << endl;
    return 0;
}