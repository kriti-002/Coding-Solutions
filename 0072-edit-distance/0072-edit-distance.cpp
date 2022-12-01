class Solution {
public:
    int help(string& w1, string& w2, int i, int j, vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        int insert=0, reduce=0, replace=0;
        if(w1[i]== w2[j]) return 0+ help(w1, w2, i-1, j-1, dp);
        else{
            insert= 1+ help(w1, w2, i-1, j, dp);
            reduce= 1+ help(w1, w2, i, j-1, dp);
            replace= 1+ help(w1, w2, i-1, j-1, dp);  
        }
        return dp[i][j]= min(insert, min(reduce, replace));
    }
    int minDistance(string word1, string word2) {
        int m= word1.length(), n=word2.length();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return help(word1, word2, m-1, n-1, dp);
    }
};