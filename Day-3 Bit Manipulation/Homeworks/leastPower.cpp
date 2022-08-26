#include <bits/stdc++.h>
using namespace std;

// Method 1 
// TC : O(log(N))
int leastPower1(int N){
    int ctr = 0 ;
    while(N && N&(N-1)){
        N = N&(N-1);
    }
    return N;
}

// Method 2
// TC : O(log(N))
int leastPower2(int N){
    int ctr = 0;
    while(N != 1){
        N >>=1;
        ctr++;
    }
    return 1 << ctr;
}

int main(){
    int N; 
    cin >> N;
    cout << leastPower1(N) << endl;
    cout << leastPower2(N) << endl;
    return 0;
}