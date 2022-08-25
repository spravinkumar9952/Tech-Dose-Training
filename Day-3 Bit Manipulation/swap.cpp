#include <bits/stdc++.h>
using namespace std;

void swap(int& A, int& B){
    A ^= B;
    B ^= A;
    A ^= B;
}

int main(){
    int A, B; 
    cin >> A >> B;

    swap(A, B) ;
    cout << A << " " << B << endl;
    return 0;
}