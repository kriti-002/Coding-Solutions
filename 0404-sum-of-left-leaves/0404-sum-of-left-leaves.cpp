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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto node= q.front(); q.pop();
            auto leftNode= node->left, rightNode= node->right;
            if(leftNode and !leftNode->left and !leftNode->right) sum+=leftNode->val;
            if(leftNode) q.push(leftNode);
            if(rightNode) q.push(rightNode);
        }
        return sum;
    }
};