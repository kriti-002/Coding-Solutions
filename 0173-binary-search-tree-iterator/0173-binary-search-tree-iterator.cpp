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
class BSTIterator {
    vector<int> in;
    int i=0;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    int next() {
        int res= in[i];
        i++;
        return res;
    }
    
    bool hasNext() {
        if(i<in.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */