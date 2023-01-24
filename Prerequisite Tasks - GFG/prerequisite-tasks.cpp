//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>adj[N];
	    for(auto x: pre){
	        adj[x.second].push_back(x.first);
	    }
	    
	    vector<int>in(N, 0);
	    for(int i=0; i<N; i++){
	        for(auto x: adj[i]){
	            in[x]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0; i<N; i++){
	        if(in[i]==0) q.push(i);
	    }
	    vector<int>t;
	    while(!q.empty()){
	        auto x= q.front(); q.pop();
	        t.push_back(x);
	        
	        for(auto y: adj[x]){
	            in[y]--;
	            if(in[y]==0) q.push(y);
	        }
	    }
	    
	    if(t.size()==N) return 1;
	    return 0;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends