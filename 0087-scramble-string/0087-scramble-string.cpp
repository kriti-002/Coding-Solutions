class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        int n=s1.length();
        vector<vector<vector<bool>>>dp(n+1, vector<vector<bool>>(n, vector<bool>(n,0)));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s1[i]== s2[j]) dp[1][i][j]=true;
            }
        }
        for(int l=2; l<=n; l++){
            for(int i=0; i< n+1-l; i++){
                for(int j=0; j<n+1-l; j++){
                    for(int nl=1; nl<l; nl++){
                        if(dp[nl][i][j] and dp[l-nl][i+nl][j+nl] or dp[nl][i][j+l-nl] and dp[l-nl][i+nl][j]) dp[l][i][j]=true;
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};