#include <bits/stdc++.h>
using namespace std;

void swap(int& A, int& B){
    A ^= B; // A = A^B
    B ^= A; // B = A^B = (A^B)^B = A 
    A ^= B; // A = A^B = (A^B)^A = B
}

int main(){
    int A, B; 
    cin >> A >> B;

    swap(A, B) ;
    cout << A << " " << B << endl;
    return 0;
}