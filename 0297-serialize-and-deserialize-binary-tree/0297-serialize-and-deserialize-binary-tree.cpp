/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode* buildTree(queue<string> &q) {
        auto s = q.front(); q.pop();
        if(s == "null") return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    void buildString(TreeNode* root, string &res){
        if(root == NULL){
            res += "null,";
            return;
        }
        
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
public:
    string serialize(TreeNode* root){ 
        string res = "";
        buildString(root, res);
        return res;
    }
    TreeNode* deserialize(string data){
        string s = ""; queue <string> q;
        
        for(auto c: data){
            if(c == ',') {
                q.push(s);
                s = "";
            }else s += c;
        }
        
        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));