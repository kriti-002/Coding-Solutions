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
    int solve(TreeNode* root){
        if(!root) return 0;
        return root->val;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int res=0;
        if(!root) return res;
        queue<TreeNode*>q; q.push(root);
        while(!q.empty()){
            auto x= q.front(); q.pop();
            if(x->val %2==0){
                if(x->left){
                    res+= solve(x->left->left)+ solve(x->left->right);
                }
                if(x->right){
                    res+=solve(x->right->left)+solve(x->right->right);
                }
            }
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        
        
        
        return res;
    }
};