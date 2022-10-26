#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int _val){
        val = _val;
        next = NULL;
    }
};

int getLen(Node* head){
    int len =0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

void append(Node **head, int val){
    Node *newNode = new Node(val);
    if(*head == NULL){
        *head = newNode;
        return ;
    }
    Node *temp = *head;

    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

void prepend(Node **head, int val){
    Node *newNode = new Node(val);
    // if head NULL return directly
    if(*head == NULL){
        *head = newNode;
        return ;
    }
    // point newNode to head
    // head to newNode
    newNode->next = *head;
    (*head) = newNode;
}

void pop_back(Node **head){
    // If list is empty
    if((*head)==NULL)
        return ;
    
    if((*head)->next == NULL){
        Node *delHead = *head;
        *head = NULL;
        delete delHead;
        return ;
    }

    Node *temp = *head;
    // interate till reach the last prev node
    while(temp->next->next){
        temp = temp->next;
    }
    
    // store int delNode to delete later
    Node *delNode = temp->next;
    temp->next = NULL;

    // free the memory
    delete delNode;
}

void pop_front(Node** head){
    if(*head==NULL)
        return ;
    
    *head = (*head)->next;
}

void deleteNode(int pos, Node** head){
    Node* temp = *head;
    int ctr = 1;
    while(ctr < pos-1 && temp){
        ctr++;
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL)
        return ;

    if(pos == 1){
        *head = (*head)->next;
        return ;
    }

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

void insert(int pos, int val, Node** head){
    int ctr = 1;
    Node* temp = *head;
    while(ctr < pos-1 && temp){
        ctr++;
        temp = temp->next;
    }

    if(pos == 1){
        Node *tempHead = *head;
        *head = new Node(val);
        (*head)->next = tempHead;
        return ;
    }
    if(temp==NULL){
        cout << "Invalid Position" << endl;
        return ;
    }
    Node* nextNode = temp->next;
    temp->next = new Node(val);
    temp->next->next = nextNode;
}

void print(Node *head){
    cout << "Linked List : " ;
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main(){
    int N;
    N = 5;

    Node *head = NULL;

    for(int i=1; i<=N; i++){
        append(&head, i);
    }
    print(head);

    insert(1, 6, &head);

    print(head);
}