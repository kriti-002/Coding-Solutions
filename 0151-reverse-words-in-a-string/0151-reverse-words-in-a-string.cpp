class Solution {
public:
    string reverseWords(string s) {
        int i=0; string res="";
        int n=s.length();
        while(i<n){
            while(i < n and s[i] == ' ') i++;
            if(i >= n) break;
            
            int j=i;
            while(j<n and s[j]!=' ') j++;
            
            string tmp=s.substr(i, j-i);
            if(res.length()==0) res=tmp;
            else res= tmp+" "+res;
            i=j+1;
        }
        return res;
    }
};