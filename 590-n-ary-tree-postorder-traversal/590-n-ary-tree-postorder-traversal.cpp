/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        
       stack<Node*> st;
       st.push(root);
        while(!st.empty()){
            auto x=st.top(); st.pop();
            for(auto y: x->children){
                st.push(y);
            }
            res.push_back(x->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};