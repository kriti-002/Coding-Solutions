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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int res=0;
        queue<pair<TreeNode* , int>>q;
        q.push({root, 0});
        while(!q.empty()){
            int size= q.size(), start= q.front().second, end= q.back().second;
            res= max(res, end-start+1);
            for(int i=0; i<size; i++){
                auto p=q.front(); q.pop();
                int idx= p.second-start;
                
                if(p.first->left != NULL)
                    q.push({p.first->left, (long long)2 * idx + 1});
                

                if(p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
            
        }
        return res;
    }
};