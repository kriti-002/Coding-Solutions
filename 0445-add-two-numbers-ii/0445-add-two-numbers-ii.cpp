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
    ListNode* reverse(ListNode* l){
        ListNode* p=NULL, *q=l, *r=NULL;
        while(q){
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        return p;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 and !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* res= new ListNode(0), *tmp=res;
        l1= reverse(l1); l2= reverse(l2);
        int carry=0;
        while(l1 or l2 or carry){
            int v1=0, v2=0;
            if(l1){
                v1=l1->val;
                l1=l1->next;
            }
            if(l2){
                v2=l2->val;
                l2=l2->next;
            }
            int sum= v1+ v2 +carry;
            carry=sum/10;
            tmp->next= new ListNode(sum%10);
            tmp=tmp->next;
        }
        res=reverse(res->next);
        return res;
    }
};