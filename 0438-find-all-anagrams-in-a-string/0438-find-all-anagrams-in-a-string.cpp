class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length(), m= p.length();
        if(m > n) return {};
        
        vector<int>v1(26,0), res;
        for(int i=0; i<m; i++) v1[p[i]-'a']++;
        
        for(int i=0, j=0; j<n; j++){
            v1[s[j]-'a']--;
            while(i<= j and v1[s[j]-'a']<0){
                v1[s[i]-'a']++;
                i++;
            }
            if(j-i+1 == m) res.push_back(i);
        }
        return res;
    }
};