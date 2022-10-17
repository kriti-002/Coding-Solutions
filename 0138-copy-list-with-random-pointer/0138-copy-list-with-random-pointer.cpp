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
        if(!head) return NULL;
        Node* iter=head , *front=head;
        while(iter){
            front=iter->next;
            Node* t= new Node(iter->val);
            iter->next=t;
            t->next=front;
            iter=front;
        }
        iter=head;
        
        while(iter){
            if(iter->random){
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
          iter = head;
          Node *newHead = new Node(0);
          Node *t = newHead;

          while (iter) {
            front = iter->next->next;
            t->next = iter->next;
            iter->next = front;
              
            t = t -> next; 
            iter = front;
          }

          return newHead->next;
    }
};