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
    void inorder(TreeNode* root, map<int,int>&m){
        if(!root) return ;
        inorder(root->left, m);
        m[root->val]++;
        inorder(root->right,m);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        map<int, int>mp;
        inorder(root, mp);
        
        int maxi=INT_MIN;
        for(auto x: mp){
            maxi=max(maxi, x.second);
        }
        for(auto x: mp){
            if(x.second== maxi) res.push_back(x.first);
        }
        return res;
        
    }
};