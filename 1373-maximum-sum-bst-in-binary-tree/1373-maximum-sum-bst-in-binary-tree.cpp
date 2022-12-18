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
    vector<int> help(TreeNode* root, int &ans){
        if (!root) return {0, INT_MAX, INT_MIN};
        vector<int> left = help(root->left, ans);
        vector<int> right = help(root->right, ans);
        
        if(left[2]< root->val and right[1]> root->val){
            ans=max(ans,root->val+left[0]+right[0]); 
            return {root->val+left[0]+right[0],
                    min(root->val,left[1]), 
                    max(root->val,right[2])};
        }
        else{
            return {0,INT_MIN,INT_MAX};
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        help(root,ans);
        return ans;
    }
};