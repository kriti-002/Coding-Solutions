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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* prev= NULL;
        ListNode* slow=head; ListNode* fast= head->next;
        head=head->next;
        while(slow and fast){
            if(prev){
                prev->next=fast;
            }
            slow->next = fast->next;
            fast->next = slow;
            prev = slow;
            slow=slow->next;
            if (slow)
                fast = slow->next;
        }
    
        return head;
    }
};