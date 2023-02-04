class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length(), n=s2.length();
        int ms1[26]={0};
        
        for(int i=0; i<m; i++) ms1[s1[i]-'a']++;
        
        for(int i=0; i<n; i++){
            bool flag=true;
            int ms2[26]={0};
            string tmp=s2.substr(i, m);
            
            for(int j=0; j<tmp.length(); j++) ms2[tmp[j]-'a']++;
            
            for(int j=0; j<26; j++){
                if(ms1[j] != ms2[j]){
                    flag=false;
                    break;
                }
            }
            if(flag) return true;
            
        }
        return false; 
    }
};