class Solution {
    char need;
    void dfs(char x,map<char,vector<char>>& mp,char parent,map<char,int>& vischeck){
        vischeck[x] = 1;
        for(auto i : mp[x]){
            if(i!=parent and vischeck[i]!=1){
            need = min(need,i);
            dfs(i,mp,x,vischeck);
            }
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        map<char,vector<char> > mp;
        for(int i=0;i<n;i++){
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }
        string ans;
        map<char,char> vis; 
        for(int i = 0;i<baseStr.size();i++){
            if(mp.find(baseStr[i])==mp.end()){
                ans+=baseStr[i];
            }
            else if(vis.find(baseStr[i])==vis.end()){
                need = baseStr[i]; 
                map<char,int> vischeck; 
                dfs(baseStr[i],mp,'0',vischeck); 
                vis[baseStr[i]] = need;
                ans+=need;
            }
            else{
                ans+=vis[baseStr[i]];
            }
            
        }
        return ans;
    }
};