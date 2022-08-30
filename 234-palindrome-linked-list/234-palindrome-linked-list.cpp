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
    ListNode *reverse(ListNode* head){
        ListNode* prev=NULL,*curr=head,*temp=NULL;
        while(curr != NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool compare(ListNode* head1, ListNode* head2){
        while(head1 and head2){
            if(head1->val != head2->val) return false;
            head1=head1->next; 
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        ListNode* slow=head; ListNode* fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        ListNode* head2=reverse(slow);
        return compare(head, head2);
    }
};