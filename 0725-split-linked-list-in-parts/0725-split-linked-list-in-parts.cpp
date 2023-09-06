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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, NULL);
        
        int len = 0;
        for (ListNode* node = head; node; node = node->next) len++;
        
        int n= len/k, r= len%k;
        ListNode* q = head, *p = NULL;
        for (int i = 0; q && i < k; i++, r--) {
            res[i] = q;
            for (int j = 0; j < n + (r > 0); j++) {
                p = q;
                q = q->next;
            }
            p->next = NULL;
        }
        return res;
    }
};