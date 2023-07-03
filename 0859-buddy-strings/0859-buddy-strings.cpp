class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!= goal.size()) return false;
        if(s==goal){
            int f[26]={0};
            for(auto c: s){
                f[c-'a']++;
                if(f[c-'a']==2) return true;
            }
            return false;
        }
        int first=-1, last=-1;
        for(int i=0; i<s.length(); i++){
            if(s[i]!= goal[i]){
                if(first==-1) first=i;
                else if(last==-1) last=i;
                else return false;
            }
        }
        if(last==-1) return false;
        return s[first]==goal[last] and s[last]==goal[first];
    }
};