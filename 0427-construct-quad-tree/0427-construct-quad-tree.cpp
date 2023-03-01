/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* help(vector<vector<int>>& grid, int rs, int re, int cs, int ce){
        if(rs> re or cs> ce) return NULL;
        
        bool isLeaf=true;
        int value= grid[rs][cs];
        for(int i=rs; i<=re; i++){
            for(int j=cs; j<=ce; j++){
                if(grid[i][j]!= value){
                    isLeaf= false;
                    break;
                }
            }
            if(!isLeaf) break;
        }
        
        if(isLeaf) return new Node(value, true);
        
        int midRow= rs+ (re-rs)/2;
        int midCol= cs + (ce-cs)/2;
        Node* root= new Node();
        root->isLeaf= 0; root->val=0;
        root->topLeft= help(grid, rs, midRow, cs, midCol);
        root->topRight= help(grid, rs,midRow, midCol+1, ce);
        root->bottomLeft= help(grid,midRow+1, re, cs, midCol);
        root->bottomRight= help(grid, midRow+1, re, midCol+1, ce);
        return root;
        
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return help(grid, 0,n-1, 0, n-1);
    }
};