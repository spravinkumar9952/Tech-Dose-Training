#include <bits/stdc++.h>
using namespace std;

int leastPower1(int N){
    int ctr = 0 ;
    while(N && N&(N-1)){
        N = N&(N-1);
    }
    return N;
}

int main(){
    int N; 
    cin >> N;
    cout << leastPower1(N) << endl;
    return 0;
}