#include <bits/stdc++.h>
using namespace std;

struct Stack{
    vector<int> st;
    int size, index;
public:
    Stack(){
        st.resize(10);
        size = 10;
        index = -1;
    }

    void push(int val){
        if(index == size-1){
            cout << "Stack is Full\n";
            return ;
        }
        st[++index] = val;
    }

    void pop(int val){
        if(this->isEmpty()){
            cout << "Stack is Empty\n";
            return ;
        }
        index--;
    }

    int top(){
        if(this->isEmpty()){
            cout << "Stack is Empty()";
            return -1;
        }
        return st[index];
    }

    bool isEmpty(){
        return index == -1;
    }
};

int main(){
       
}