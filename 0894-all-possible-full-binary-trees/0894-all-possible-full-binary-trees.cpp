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
    unordered_map<int, vector<TreeNode*>>mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1) return {new TreeNode()};
        if(n%2==0) return {};
        if(mp.find(n)!= mp.end()) return mp[n];
        
        vector<TreeNode*> res;
        for(int i=1; i<n; i+=2){
            vector<TreeNode*> left= allPossibleFBT(i), right= allPossibleFBT(n-i-1);
            for(TreeNode* l: left){
                for(TreeNode* r: right){
                    TreeNode* root= new TreeNode(0,l,r);
                    res.push_back(root);
                }
            }
        }
        return mp[n]=res;
    }
};