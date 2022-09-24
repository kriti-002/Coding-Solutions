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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>res;
        dfs(root, targetSum,path, res);
        return res;   
    }
    private:
    void dfs(TreeNode* root, int targetSum, vector<int>&path, vector<vector<int>>& res){
        if(!root) return;
        path.push_back(root->val);
        
        if(!root->left and !root->right and targetSum==root->val) res.push_back(path);
        dfs(root->left, targetSum-root->val, path, res);
        dfs(root->right, targetSum-root->val, path, res);
        path.pop_back();
    }
};