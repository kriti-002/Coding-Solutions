/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 and list2) return list2;
        if(list1 and !list2) return list1;
        if(!list1 and !list2) return NULL;
        
        ListNode* res= new ListNode(0);
        ListNode* tmp= res;
        ListNode* p= list1, *q= list2;
        
        while(p and q){
            if(p->val < q->val){
                tmp->next=p;
                p=p->next;
            }else{
                tmp->next=q;
                q=q->next;
            }
            tmp=tmp->next;
        }
        if(p){
            tmp->next=p;
            p=p->next;
        }
        if(q){
            tmp->next=q;
            q=q->next;
        }
        return res->next;
        
    }
};