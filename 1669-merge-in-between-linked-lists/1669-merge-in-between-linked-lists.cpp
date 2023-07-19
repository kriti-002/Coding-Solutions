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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int jump1 = 1;
        ListNode *p = list1, *q = list1;
        while (jump1 < a){
            p = p->next;
            jump1++;
        }                                //Gets the pointer to a
        
		int jump2 = 1;
        while(jump2 <= b){
            q = q->next;
            jump2++;
        }
        ListNode *u=list2;
        while(u->next) u=u->next;
        p->next=list2;
        u->next=q->next;
        return list1;
    }
};