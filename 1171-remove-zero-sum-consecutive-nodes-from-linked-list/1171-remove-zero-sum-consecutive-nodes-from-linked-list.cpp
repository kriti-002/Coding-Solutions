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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* p= head;
        ListNode* res=NULL;
        vector<int> arr;
        while(p){
            arr.push_back(p->val);
            p=p->next;
        }
        int sum, j;
        for(int i=0; i<arr.size(); i++){
            sum=0;
            for(j=i; j<arr.size(); j++){
                sum+=arr[j];
                if(sum==0) break;
            }
            if(sum==0) {
                arr.erase(arr.begin()+i,arr.begin()+j+1);
                i--;
            }
        }
        if(arr.size()==0) return NULL;
        else{
            ListNode* root = new ListNode(arr[0]);
            p = root;
            for (auto i=1;i<arr.size();i++)
            {
                ListNode* temp = new ListNode;
                temp->val=arr[i];
                root->next=temp;
                root=root->next;
            }
        }
        return p;
    }
};