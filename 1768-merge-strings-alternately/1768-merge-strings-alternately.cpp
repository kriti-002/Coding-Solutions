class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int n=min(word1.length(), word2.length());
        int i=0;
        for(i=0; i<n; i++){
            res+=word1[i];
            res+=word2[i];
        }
        if(word1.length() > word2.length()){
            res+=word1.substr(i, word1.length());
        }else{
            res+=word2.substr(i,word2.length());
        }
        return res;
    }
};