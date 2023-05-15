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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p=head, *q=head, *r=head;
        int count=1;
        while(r){
            r=r->next;
            count++;
        }
        for(int i=1; i<k; i++) p=p->next;
        for(int i=1; i<count-k; i++) q=q->next;
        
        int tmp=p->val;
        p->val=q->val;
        q->val=tmp;
        
        return head;
    }
};