class Solution {
    int help(int i, int j, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]= triangle[i][j]+ min(help(i+1,j+1, triangle, dp), help(i+1, j, triangle, dp));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1) return triangle[0][0];
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return help(0,0,triangle, dp);
    }
};