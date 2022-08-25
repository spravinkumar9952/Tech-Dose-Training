#include <bits/stdc++.h>
using namespace std;

bool isSetBit(int N, int pos){
    return ( N & (1<<(pos-1)) )!= 0;
}

int main(){
    int N, pos; 
    cin >> N >> pos;
    cout << isSetBit(N, pos) << endl;
    return 0;
}