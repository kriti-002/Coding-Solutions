class Solution {
    vector<int> dijkstra(int S,vector<vector<pair<int,int>>> &adj,int n){
	            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	vector<int> dist(n,INT_MAX);

	pq.push({0,S});
	dist[S]=0;

	while(!pq.empty()){
		auto node=pq.top(); pq.pop();
		int v=node.second;

		for(auto x: adj[v]){
			if(dist[v]+x.second<dist[x.first]){
				dist[x.first]=dist[v]+x.second;
				pq.push({dist[x.first],x.first});
			}
		}
	}
	return dist;
}
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int v= edges.size(), res=0, mini=INT_MAX;
        vector<vector<pair<int, int>>>adj(v);
        for(int i=0; i<v; i++){
            if(edges[i]!=-1) adj[i].push_back({edges[i],1});
        }
        vector<int>d1=dijkstra(node1, adj, v), d2= dijkstra(node2, adj, v);
        for(int i=0;i<v;i++){
            if(mini> max(d1[i],d2[i])){
                mini=min(mini,max(d1[i],d2[i]));
                res=i;
            }
	    }
	    return (mini==INT_MAX)?-1: res;
        
    }
};