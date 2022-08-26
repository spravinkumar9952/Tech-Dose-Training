#include <bits/stdc++.h>
using namespace std;

int unsetIthBit(int N, int pos){
    return N & ( ~( 1<< (pos-1) ) );
}

int main(){
    int N, pos; 
    cin >> N >> pos;

    cout << unsetIthBit(N, pos) << endl;
    return 0;
}