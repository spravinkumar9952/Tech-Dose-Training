/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        
        for(Node* i = head; i; i= i->next->next){
            Node *next = i->next;
            i->next = new Node(i->val);
            i->next->next = next;
        }
        
        
        Node *ans = head->next, *copyAns = ans;
        for(Node *i = head; i; i=i->next->next){
            if(i->random)
                i->next->random = i->random->next;
        }
        
        for(Node *i = head; i; i=i->next){
            i->next = i->next->next;
            
            if(copyAns->next){
                copyAns->next = copyAns->next->next;
                copyAns = copyAns->next;
            }
        }
        
        return ans;
    }
};