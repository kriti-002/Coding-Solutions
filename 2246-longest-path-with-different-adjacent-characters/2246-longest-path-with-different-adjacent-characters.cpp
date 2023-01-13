class Solution {
    int help(int i,int &res,vector<int>g[], string &s){
        int big1 = 0, big2 = 0;
        for (auto j : g[i]) {
            int cur = help(j,res,g,s);
            if (s[i] == s[j]) continue;
            if (cur > big2) big2 = cur;
            if (big2 > big1) swap(big1, big2);
        }
        res = max(res, big1 + big2 + 1);
        return big1 + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size(), res=0;
        vector<int>g[n];
        for(int i=1; i<n; i++){
            g[parent[i]].push_back(i);
            //g[i].push_back(parent[i]);
        }
        help(0,res,g, s);
        return res;
    }
};