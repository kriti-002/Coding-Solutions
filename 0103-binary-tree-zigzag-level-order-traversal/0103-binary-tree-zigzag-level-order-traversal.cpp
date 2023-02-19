/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res; int count=0;
        queue<TreeNode*>q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int size=q.size();
            while(size--){
                auto tmp=q.front(); q.pop();
                temp.push_back(tmp->val);
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            if(count%2==1){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            count++;
        }
        return res;
    }
};