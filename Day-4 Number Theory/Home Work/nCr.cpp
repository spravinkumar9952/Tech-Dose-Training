#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getCombinationTable(int N){
    vector<vector<int>> combTable(N+1);

    for(int i=0; i<=N; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i){
                combTable[i].push_back(1);
            }else{
                combTable[i].push_back(combTable[i-1][j]+combTable[i-1][j-1]);
            }
        }
    }
    return combTable;
}

int main(){
    int N, R; cin >> N >> R;   

    vector<vector<int>> combTable = getCombinationTable(N); 

    for(auto i : combTable){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << N << "C" << R << " = " << combTable[N][R]  << endl;

    return 0;
}