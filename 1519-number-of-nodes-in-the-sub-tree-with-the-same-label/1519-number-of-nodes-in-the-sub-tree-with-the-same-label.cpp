class Solution {
    vector<int> help(int i, int p, vector<int>g[], string &labels, vector<int>&res){
        vector<int>nodeCounts(26);
        for(auto x: g[i]){
            if(x!=p){
                vector<int> tmp=help(x, i, g, labels, res);
                for(int i=0;i<26;i++) 
                    nodeCounts[i]+=tmp[i];
            }
        }
        res[i]=++nodeCounts[labels[i]-'a'];
        return nodeCounts;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>g[n];
        for(auto x: edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<int> res(n);
        help(0, -1, g, labels, res);
        return res;
        
    }
};