class Solution {
public:
    bool help(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i<0 and j<0) return true;
		if(i<0 and j>=0) return false;
		if(j<0 and i>=0){
			for(int k=i;k>=0;k--){
				if(p[k]!='*') return false;
			}
			return true;
		}
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(p[i]=='*') return dp[i][j]= help(i-1, j, s, p, dp) or help(i, j-1, s, p, dp);
        if(p[i]=='?' or p[i]==s[j]) return dp[i][j]= help(i-1, j-1, s, p, dp);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m=s.length(), n=p.length();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return help(n-1, m-1, s, p, dp);
    }
};