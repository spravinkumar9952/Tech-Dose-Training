#include <bits/stdc++.h>
using namespace std;

int rightMostOne(int N){
    return N & (~N+1) ;
}

int rightMostOnePosition(int N){
    int pos = 0;
    while( (N&1) ==0 ){
        N >>= 1;
        pos++;
    }
    return pos+1;
}

int main(){
    int N; 
    cin >> N;

    // give the right most setBit value Not position
    cout << rightMostOne(N) << endl;

    // rightmost setbit possition 
    cout << rightMostOnePosition(N) << endl;
    return 0;
}