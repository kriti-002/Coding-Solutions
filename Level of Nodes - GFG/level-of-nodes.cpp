//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    int lvlcnt=0;
        queue<int> q;
        vector<bool> visited(V,false);
        q.push(0);
        visited[0] =1;
        while(!q.empty()){
            
            int size = q.size();
            for(int i=0;i<size;i++){
               int frontnode = q.front();
                q.pop();
                if(frontnode == X) return lvlcnt;
                
                for(auto itr:adj[frontnode]){
                    if(!visited[itr]){
                        q.push(itr);
                        visited[itr] =1;    
                    }
                }
            }
            lvlcnt++;
        }
        return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends