class Solution {
    int dp[102][102];
    bool help(string &s1, string &s2, string &s3, int i, int j, int k){
        
        if(k >= s3.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool flag1 = false, flag2 = false;
        if(s1[i] == s3[k]){
            flag1 =  help(s1, s2, s3, i + 1, j, k + 1);
        }
        
        if(s2[j] == s3[k]){
            flag2 =  help(s1, s2, s3, i, j + 1, k + 1);
        }
    
        return dp[i][j] = (flag1 || flag2);
        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a= s1.size(), b= s2.size(), c= s3.size();
        if(a+b != c) return false;
        memset(dp, -1,sizeof(dp));
        return help(s1,s2,s3,0,0,0);
    }
};