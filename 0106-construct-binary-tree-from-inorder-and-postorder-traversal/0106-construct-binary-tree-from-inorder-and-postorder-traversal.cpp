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
    int search(vector<int> inorder, int data, int n){
        for(int i=0; i<n; i++){
            if(inorder[i]== data){
                return i;
            }
        }
        return -1;
    }
    TreeNode* help(vector<int> inorder, vector<int> postorder,int &index,int start,int end, int n){
        if(start > end or index>=n) return NULL;
        int ele= postorder[index--];
        TreeNode *root= new TreeNode(ele);
        int idx= search(inorder, ele, n);
        
        root->right= help(inorder, postorder, index, idx+1, end, n);
        root->left= help(inorder, postorder, index, start, idx-1, n);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        return help(inorder, postorder, index, 0, index, index+1);
    }
};