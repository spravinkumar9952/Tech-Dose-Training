#include <bits/stdc++.h>
using namespace std;

char toLower(char ch){
    // set the 6th bit == ch + 32 (only if already bit is seted. else ch + 0)
    // 'A'+32 = 'a' 
    return ch | (1<<5);
}

char toUpper(char ch){
    // unset the 6th bit == ch - 32 (only if already bit is unsetted. else ch - 0)
    // 'a'-32 = 'A'
    return ch & ( ~(1<<5) );
}

char toToggle(char ch){
    // it is just toggle th 6th bit 
    return ch ^ (1<<5);
}

int main(){
    char ch;
    cin >> ch;

    cout << toLower(ch) << endl;
    cout << toUpper(ch) << endl;
    cout << toToggle(ch) << endl;

    return 0;
}