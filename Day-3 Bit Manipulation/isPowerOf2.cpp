#include <bits/stdc++.h>
using namespace std;

bool isPowerOf2(int N){
    return N>0 && N&(N-1)==0;
}

int main(){
    int N; cin >> N;
    cout << (isPowerOf2(N) ? "True" : "False") << endl; 
}