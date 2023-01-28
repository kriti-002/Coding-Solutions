//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DS{
    public: 
    vector<int> rank, parent;
    DS(int n){
        rank.resize(n,0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int findPar(int node){
        if(parent[node]== node) return node;
        return parent[node]= findPar(parent[node]);
    }
    void UnionByRank(int u, int v){
        int ultimateParU= findPar(u), ultimateParV= findPar(v);
        if(ultimateParU == ultimateParV) return;
        
        if(rank[ultimateParU] < rank[ultimateParV]){
            parent[ultimateParU]= parent[ultimateParV];
        }else if(rank[ultimateParU] > rank[ultimateParV]){
            parent[ultimateParV] = parent[ultimateParU];
        }else{
            parent[ultimateParU]= parent[ultimateParV];
            rank[ultimateParU]= rank[ultimateParV]++;
        }
        
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DS *d= new DS(n);
        int extra=0;
        for(auto x: edge){
            int u=x[0], v=x[1];
            
            if(d->findPar(u)== d->findPar(v)) extra++;
            else d->UnionByRank(u,v);
        }
        int conn=0;
        for(int i=0; i<n ;i++){
            if(d->parent[i]==i) conn++;
        }
        if(extra >= conn-1) return conn-1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends