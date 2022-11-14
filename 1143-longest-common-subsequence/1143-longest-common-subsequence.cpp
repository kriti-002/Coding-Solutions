class Solution {
public:
    int help(string &t1, string &t2,vector<vector<int>>&dp, int i, int j){
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(t1[i]== t2[j]) return dp[i][j]=1+ help(t1, t2,dp, i-1, j-1);
        else return dp[i][j]=max(help(t1, t2,dp, i-1, j),help(t1, t2, dp,i, j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(), n=text2.length();
        if(text1== text2) return m;
        vector<vector<int>>dp(m,vector<int>(n, -1));
        return help(text1, text2,dp, m-1, n-1);
    }
};