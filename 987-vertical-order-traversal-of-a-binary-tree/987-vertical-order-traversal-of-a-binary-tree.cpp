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
    void help(TreeNode* root,int row,int col,map<int, vector<pair<int, int>>>&mp){
        if(!root) return;
        
        mp[col].push_back({row,root->val});
        help(root->left,row+1,col-1,mp);
        help(root->right,row+1,col+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        map<int,vector<pair<int, int>>>mp;
        help(root,0, 0, mp);
        for(auto x: mp){
            sort(x.second.begin(), x.second.end());
            vector<int>tmp;
            for(auto y: x.second){
                tmp.push_back(y.second);
            }
            res.push_back(tmp);
        }
        return res;
    }
};