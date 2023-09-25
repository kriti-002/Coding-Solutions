class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for(auto x: t) m[x]++;
        for(auto x: s){
            if(m[x]) m[x]--;
        }
        char res;
        for(auto x: m){
            if(x.second==1) res=x.first;
        }
        return res;
    }
};