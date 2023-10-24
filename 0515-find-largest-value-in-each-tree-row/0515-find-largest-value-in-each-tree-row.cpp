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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int>res;
        int n,maxi;
        queue<TreeNode*>q;
        q.push(root);
        while(true){
            n=q.size();
            if(n==0) break;
            maxi=INT_MIN;
           while(n--){
                TreeNode* x=q.front(); q.pop();
                if(maxi < x->val){
                    maxi=x->val;
                }
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }         
        } 
            res.push_back(maxi);  
    }
        
        return res;
    }
};