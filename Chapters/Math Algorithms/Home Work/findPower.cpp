#include <bits/stdc++.h>
using namespace std;

#define ll long long

// TC : O(log(power))
ll getPower(ll base, ll power){
    int res = 1;

    while(power > 0){
        if(power %2 == 1){
            res *= base;
        }
        base = base * base;
        power /= 2;
    }

    return res;
}


int main(){
    ll base, power; 
    cin >> base >> power;

    cout << getPower(base , power) << endl;   
    return 0;
}