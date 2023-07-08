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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        map<int,int>mp;
        ListNode* p=head;
        while(p){
            mp[p->val]++;
            p=p->next;
        }
        ListNode* res=new ListNode(0), *tmp=res;
        for(auto m: mp){
            if(m.second==1){
                ListNode* t= new ListNode(m.first);
                tmp->next=t;
                tmp=t;
            }
        }
        return res->next;
    }
};