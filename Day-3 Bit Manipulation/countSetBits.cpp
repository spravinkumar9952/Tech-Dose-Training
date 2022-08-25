#include <bits/stdc++.h>
using namespace std;

// method 1
int countSetBits1(int N){
    int ctr= 0;
    for(int i=1; i<N; i<<=1){
        if(N&i){
            ctr++;
        }
    }
    return ctr;
}

// method 2
int countSetBits2(int N){
    int ctr = 0;
    while(N){
        N = N&(N-1);
        ctr++;
    }
    return ctr;
}

// method 3
int countSetBits3(int N){
    int ctr = 0;
    while(N){
        ctr += N&1;
        N >>=1;
    }
    return ctr;
}

// method 4
int countSetBits4(int N){
    return __builtin_popcount(N);
}


int main(){
    int N; 
    cin >> N;

    cout << countSetBits1(N) << endl;
    cout << countSetBits2(N) << endl;
    cout << countSetBits3(N) << endl;
    cout << countSetBits4(N) << endl;
    
    return 0;
}