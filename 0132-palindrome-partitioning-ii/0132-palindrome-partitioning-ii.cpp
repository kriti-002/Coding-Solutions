class Solution {
public:
    bool isPalin(int i, int j, string&s){
        while(i<j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    int help(int i, int j, string& s, vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(isPalin(i,j,s)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        for(int k=i; k<j; k++){
            if(isPalin(i,k,s)){
                int tmp= 1+ help(k+1, j, s, dp);
                mini=min(mini, tmp);
            }
        }
        return dp[i][j]=mini;
    }
    int minCut(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return help(0, n-1, s, dp);
    }
};