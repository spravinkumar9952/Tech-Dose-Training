#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next, *prev;
    Node(int val){
        this->val = val;
        next = prev = NULL;
    }
};

void print(Node *head, Node*tail){
    cout << "Forward List : ";
    for(Node *i = head; i!=NULL ; i= i->next){
        cout << i->val << "->";
    }
    cout << "NULL" << endl;

    cout << "Reverse List : ";
    for(Node *i= tail; i!=NULL; i=i->prev){
        cout << i->val << "->";
    }
    cout << "NULL" << endl;
}

void append(Node** head, Node** tail, int val){
    Node* newNode = new Node(val);
    if((*head)== NULL){
        (*head) = (*tail) = newNode;
        return ;
    }
    (*tail)->next = newNode;
    newNode->prev = (*tail);
    (*tail) = (*tail)->next;
}

void prepend(Node** head, Node** tail, int val){
    if((*head)==NULL){
        (*head) = (*tail) = new Node(val);
        return ;
    }
    (*head)->prev = new Node(val);
    (*head)->prev->next = (*head);
    (*head) = (*head)->prev;
}

void deleteNode(Node** head, Node** tail, int pos){
    if((*head)==NULL){
        cout << "Linked List is Empty" << endl;
        return ;
    }

    int ctr = 1;
    Node *temp = *head;
    while(ctr < pos-1 && temp){
        temp = temp->next;
        ctr++;
    }

    if(temp == NULL){
        cout << "Invalid Position" << endl;
        return ;
    }

    if(pos == 1){
        if((*head)==(*tail)){
            (*head) = (*tail) = NULL;
        }else{
            temp = temp->next;
        }
        return ;
    }else{
        
        Node* delNode = temp->next;
        if(temp->next == (*tail)){
            *tail = (*tail)->prev;
        }
        temp->next = temp->next->next;
        temp->next->prev = temp;
    }
}


int main(){
    int N;
    N = 5;

    Node *head = NULL, *tail = NULL;
    for(int i=1; i<=N; i++){
        prepend(&head, &tail, i);
    }

    print(head, tail);
}