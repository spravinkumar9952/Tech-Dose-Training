#include <bits/stdc++.h>
using namespace std;

char toLower(char ch){
    return ch | (1<<5);
}

char toUpper(char ch){
    return ch & ( ~(1<<5) );
}

char toToggle(char ch){
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