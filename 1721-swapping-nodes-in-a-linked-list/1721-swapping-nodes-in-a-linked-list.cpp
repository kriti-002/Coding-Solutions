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
            if(count< k){
                p=p->next;
            }else if(count > k){
                q=q->next;
            }
            r=r->next;
            count++;
        }
        int tmp=p->val;
        p->val=q->val;
        q->val=tmp;
        
        return head;
    }
};