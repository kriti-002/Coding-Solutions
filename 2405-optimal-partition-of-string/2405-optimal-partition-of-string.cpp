class Solution {
public:
    int partitionString(string s) {
        vector<int> vis(26,-1);
        int res=1, j=0, n=s.length();
        for(int i=0; i<n; i++){
            if(vis[s[i]-'a'] >= j){
                res++;
                j=i;
            }
            vis[s[i]-'a']=i;
        }
        return res;
    }
};