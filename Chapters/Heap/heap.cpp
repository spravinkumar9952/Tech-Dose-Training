#include <bits/stdc++.h>
using namespace std;


// Max Heap (1 index based)
struct Heap{
    vector<int> heap;
    int size, MaxSize;
    Heap(){
        size = 0;
        heap.resize(2);
    }

    // UpTree is Ok but downTree is Not Ok
    // TC -> O ( log(N) )
    void heapifyDown(int par){
        int left = getLeft(par);
        int right = getRight(par);

        int largest = par;
        if(left <= size && heap[left]>heap[largest]){
            largest = left;
        }
        if(right <= size && heap[right] > heap[largest]){
            largest = right;
        }
        if(largest != par){
            swap(heap[par], heap[largest]);
            heapifyDown(largest);
        }
    }

    // DownTree is Ok but upTree is affected
    // TC -> O(long(N))
    void heapifyUp(int pos){
        for(int i=pos; i>1 && heap[getParent(i)]<heap[i]; i = getParent(i)){
            swap(heap[getParent(i)], heap[i]);
        }
    }

    // getThe top of the heap
    // TC : O(1)
    int top(){
        if(size == 0){
            cout << "Heap is Empty!" << endl;
            return -1;
        }

        return heap[1];
    }

    // remove the top
    // TC : O(log(N))
    void pop(){
        if(size == 0){
            cout << "Heap is Empty!" << endl;
            return ;
        }

        heap[1] = heap[size--];
        heapifyDown(1);
    }

    // add to the heap
    // TC : O(log(N))
    void push(int val){
        if(heap.size()==size+1){
            heap.resize(2*size+1);
        }

        heap[++size] = val;
        heapifyUp(size);
    }

    // heap is empty or not
    bool isEmpty(){
        return size == 0;
    }

    // left child (1 based index)
    int getLeft(int par){
        return 2*par;
    }

    // right child (1 based index)
    int getRight(int par){
        return 2*par+1;
    }

    // parent node (1 based index)
    int getParent(int child){
        return child/2;
    }
};

int main(){

    vector<int> arr = {0 , 2 , 4 , 1, 9, -1, 8, 19};

    Heap hp;

    for(int i : arr)
        hp.push(i);
    // hp.buildHeap(arr);
    // hp.push(9);
    // hp.push(3);
    // hp.push(7);
    // hp.push(5);

    while(!hp.isEmpty()){
        cout << hp.top() << " ";
        hp.pop();
    }
    cout << endl;

    return 0;
}
    