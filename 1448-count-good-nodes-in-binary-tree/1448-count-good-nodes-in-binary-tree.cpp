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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int count=1;
        while(!q.empty()){
            auto x=q.front().first;
            auto data=q.front().second;
            q.pop();
            if(x->left){
                if(x->left->val >= data){
                    count++;
                    q.push({x->left, x->left->val});
                }else q.push({x->left, data});
                
            }
            if(x->right){
                if(x->right->val >= data){
                    count++;
                    q.push({x->right, x->right->val});
                }else q.push({x->right, data});
                
            } 
        }
        return count;
    }
};