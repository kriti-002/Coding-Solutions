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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        if(!root) return res;
        
        queue<TreeNode*> q; q.push(root);
        
        while(!q.empty()){
            int n=q.size(); long tmp=0;
            for(int i=0; i<n; i++){
                auto x= q.front(); q.pop();
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
                tmp+=x->val;   
            }
            res.push_back((double)tmp/n);
        }
        return res;
    }
};