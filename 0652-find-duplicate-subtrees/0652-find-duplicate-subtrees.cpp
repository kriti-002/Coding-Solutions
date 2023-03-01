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
    string help(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& res){
        if(!root) return "#";
        
        string leftId = help(root->left, mp, res);
        string rightId = help(root->right, mp, res);
        
        string id = to_string(root->val) + "," + leftId + "," + rightId;
        mp[id]++;
        
        if(mp[id]==2) res.push_back(root);
        return id;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> mp;
        help(root, mp, res);
        return res;
    }
};