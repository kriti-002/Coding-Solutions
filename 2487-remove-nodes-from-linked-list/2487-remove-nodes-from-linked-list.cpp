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
    ListNode* removeNodes(ListNode* head) {
        if(!head or !head->next) return head;
        deque<int>s;
        ListNode* p=head;
        while(p){
            while(!s.empty() and s.back()<p->val) s.pop_back();
            s.push_back(p->val);
            p=p->next;
        }
        p=head;
        ListNode* res=NULL, *tmp=res;
        while(p){
            if(p->val== s.front()){
                if(!res) res=tmp=p;
                else{
                    tmp->next=p;
                    tmp=tmp->next;
                }
                s.pop_front();
            }
            p=p->next;
        }
        return res;
    }
};