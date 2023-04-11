/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* src, Node* node, vector<Node*>&vis){
        vis[node->val]=node;
        for(auto x: src->neighbors){
            if(!vis[x->val]){
                Node* newNode= new Node(x->val);
                (node->neighbors).push_back(newNode);
                dfs(x,newNode,vis);
            }else{
                (node->neighbors).push_back(vis[x->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node== NULL) return NULL;
        vector<Node*> visited(1000, NULL);
        Node* copy= new Node(node->val);
        visited[node->val]=copy;
        for(auto x: node->neighbors){
            if(!visited[x->val]){
                Node* newNode= new Node(x->val);
                copy->neighbors.push_back(newNode);
                dfs(x, newNode, visited);
            }else{
                copy->neighbors.push_back(visited[x->val]);
            }
        }
       return copy; 
    }
};