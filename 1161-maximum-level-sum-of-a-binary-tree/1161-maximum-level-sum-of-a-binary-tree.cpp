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
    int maxLevelSum(TreeNode* root) {
        int sum=INT_MIN, res=0, level=0;
        if(!root) return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            level++;
            int tmp=0, size=q.size();
            while(size--){
                auto x= q.front(); q.pop();
                tmp+=x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            if(sum < tmp){
                    sum=tmp;
                    res=level;
            }
        }
        return res;
    }
};