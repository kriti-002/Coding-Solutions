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
    void buildGraph(vector<vector<int>>&graph, TreeNode*root){
        if(!root) return;
        
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        buildGraph(graph, root->left);
        buildGraph(graph, root->right);
        
    }
    int amountOfTime(TreeNode* root, int start) {
        int res=0;
        vector<vector<int>>graph(100001);
        vector<bool>vis(100001);
        
        buildGraph(graph, root);
        queue<int>q; q.push(start);
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0; i<s; i++){
                auto x= q.front(); q.pop();
                vis[x]=1;
                for(auto y: graph[x]){
                    if(!vis[y]){
                        q.push(y);
                    }
                }
            }
            res++;
        }
        return res-1;
    }
};