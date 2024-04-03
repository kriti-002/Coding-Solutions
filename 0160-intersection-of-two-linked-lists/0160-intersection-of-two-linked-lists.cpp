/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int len(ListNode* head){
        int count=0;
        ListNode* p= head;
        while(p){
            count++;
            p=p->next;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA= len(headA), lenB=len(headB);
        ListNode* p= headA, *q= headB;
        while(lenA> lenB){
            lenA--;
            p=p->next;
        }
        while(lenB > lenA){
            lenB--;
            q=q->next;
        }
        while(p!=q){
            p=p->next;
            q=q->next;
        }
        return p;
    }
};