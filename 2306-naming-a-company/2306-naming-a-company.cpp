class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        set<string>st[26];
        for(auto idea: ideas){
            st[idea[0]-'a'].insert(idea.substr(1));
        }
        long long res=0;
        int n=ideas.size();
        for(int i=0; i<25; i++){
            for(int j=i+1; j<26; j++){
                long same=0;
                for(auto idea: st[i]){
                    if(st[j].count(idea))same++;
                }
                res += 2*(st[i].size()-same)*(st[j].size()-same);
            }
        }
        return res;
    }
};