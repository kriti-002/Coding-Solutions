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
    string r;
    string smallestFromLeaf(TreeNode* root) {
        
        help(root,"");
        return r;
    }
    void help(TreeNode* root,string t){
        if(!root) return;
        
        t= char(root->val + 'a') +t;
        if(!root->left and !root->right){
            if(r=="" or r > t) r=t;
        }
            
        if(root->left) help(root->left, t);
        if(root->right) help(root->right, t); 
    }
};