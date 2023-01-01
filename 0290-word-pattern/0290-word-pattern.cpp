class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string>hashP;
        vector<string> v;
        
        int j=0, n=s.length();
        string tmp="";
        while(j<n){
              if(s[j]== ' '){
                v.push_back(tmp);
                tmp="";
            }
            else{
                tmp+=s[j];
            }
            j++;
        }
        v.push_back(tmp);
        if(v.size()!=pattern.size()) return false;
        set<string>st;
        for(int i=0;i<pattern.size();i++){
            if(hashP.find(pattern[i])!=hashP.end()){
                if(hashP[pattern[i]]!=v[i]) return false;
            }
            else{
                if(st.count(v[i])>0) return false;
                hashP[pattern[i]]=v[i];
                st.insert(v[i]);
            }
        }
        return true;
    }
};