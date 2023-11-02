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
    void help(TreeNode* root, int &res)
    {
        int sum=0, count=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                auto x = q.front(); q.pop();
                sum += x->val;
                count++;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        if(sum/count == root->val) res++;
    }
    int averageOfSubtree(TreeNode* root) {
        int res=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                auto x = q.front(); q.pop();
                help(x, res);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        return res; 
    }
};