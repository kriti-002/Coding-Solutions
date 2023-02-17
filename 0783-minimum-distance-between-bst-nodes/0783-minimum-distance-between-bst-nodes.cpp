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
    int res=INT_MAX, p=-1;
public:
    int minDiffInBST(TreeNode* root) {
        if (root->left) minDiffInBST(root->left);
        if (p >= 0) res = min(res, root->val - p);
        p = root->val;
        if (root->right) minDiffInBST(root->right);
        return res;
    }
};