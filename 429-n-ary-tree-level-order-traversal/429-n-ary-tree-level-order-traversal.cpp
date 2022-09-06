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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        if(! root) return {};
        vector<vector<int>>res;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size(); vector<int>tmp;
            while(n--){
                
            auto x= q.front();
            q.pop();
            tmp.push_back(x->val);
            int size= (x->children).size();
            for(int i=0; i<size; i++){
               q.push(x->children[i]); 
            }
        }
            res.push_back(tmp);
            
        }
        return res;
    }
};