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
    void help(TreeNode* root, bool left, int path, int&res){
        if(!root) return;
        res=max(res, path);
        if(left){
            help(root->left, 0, path+1, res);
            help(root->right, 1, 1, res);
        }else{
            help(root->left, 0, 1, res);
            help(root->right, 1,path+1, res);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int res=0, path=0;
        help(root, true, path, res);
        help(root, false, path, res);
        return res;
    }
};