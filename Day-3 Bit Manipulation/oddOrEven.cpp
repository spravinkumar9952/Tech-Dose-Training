#include <bits/stdc++.h>
using namespace std;

bool oddOrEven(int N){
    return (N&1) != 0;
}

int main(){
    int N; cin >> N;
    cout << (oddOrEven(N) == true ? "Odd" : "Even" )<< endl;
    return 0;
}