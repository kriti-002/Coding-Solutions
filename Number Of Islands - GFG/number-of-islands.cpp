//{ Driver Code Starts
// Initial Template for C++

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>>mat(n, vector<int>(m,0));
        vector<vector<int>>vis(n, vector<int>(m,0));
        vector<int>res;
        
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        
        int island=0;
        DS *d= new DS(n*m);
        for(auto x: operators){
            int r=x[0], c=x[1];
            mat[r][c]=1;
            int node= r*m + c;
            
            if(vis[r][c]==0){
                vis[r][c]=1;
                island++;
                for(int i=0; i<4; i++){
                    int row= r+ delRow[i], col= c+ delCol[i];
                    if(row >=0 and row< n and col>=0 and col<m and mat[row][col]==1){
                        int adjNode= row*m + col;
                        if(d->findPar(node) != d->findPar(adjNode)){
                            d->UnionByRank(node, adjNode);
                            island--;
                        }
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends