#include <bits/stdc++.h>
using namespace std;


int countSetBits1(int N){
    int ctr= 0;
    for(int i=1; i<N; i<<=1){
        if(N&i){
            ctr++;
        }
    }
    return ctr;
}

int countSetBits2(int N){
    int ctr = 0;
    while(N){
        N = N&(N-1);
        ctr++;
    }
    return ctr;
}

int countSetBits3(int N){
    int ctr = 0;
    while(N){
        ctr += N&1;
        N >>=1;
    }
    return ctr;
}

int countSetBits4(int N){
    return __builtin_popcount(N);
}


int main(){
    int N; 
    cin >> N;
    cout << countSetBits1(N);
    cout << countSetBits2(N);
    cout << countSetBits3(N);
    cout << countSetBits4(N);
    return 0;
}