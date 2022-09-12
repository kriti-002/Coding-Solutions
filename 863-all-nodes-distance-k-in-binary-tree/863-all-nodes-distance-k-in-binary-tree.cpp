/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* root, unordered_map<int, vector<int>>& graph){
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left, graph);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right, graph);
        }  
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        if(k==0) return {target->val};
        
        int count=0;
        unordered_map<int, vector<int>>graph;
        unordered_map<int, bool>vis;
        buildGraph(root, graph);
        
        queue<int>q;
        q.push(target->val);
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0; i<s; i++){
                int x= q.front(); q.pop();
                vis[x]=1;
                for(int y: graph[x]){
                    if(!vis[y]) q.push(y);
                }
            }
            count++;
            if(count==k){
                while(!q.empty()){
                    res.push_back(q.front());
                    q.pop();
                    }
                break;
            }   
        }
        return res;
    }
};