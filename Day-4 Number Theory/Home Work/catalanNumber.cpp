#include <bits/stdc++.h>
using namespace std;


// TopDown Approach
// TC : O(N)
// SC : O(N)

vector<int> catalan;

int getCatalan(int N){
    if(N==0 || N==1) 
        return 1;
    
    if(catalan[N]!=-1)
        return catalan[N];

    int currCatalan = 0;
    for(int i=0; i<N; i++){
        currCatalan += getCatalan(i)*getCatalan(N-i-1);
    }

    return catalan[N] = currCatalan;
}

int main(){
    int N; 
    cin >> N;

    catalan.resize(N+1, -1);

    cout << getCatalan(N) << endl;   
    return 0;
}