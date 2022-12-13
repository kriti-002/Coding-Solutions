class Solution {
public:
int help(vector<vector<int>>& matrix, vector<vector<int>>&dp, int i, int j){
    if(j<0 or j>=matrix[0].size()) return 1e8;
    if(i==0) return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];

    int up=matrix[i][j]+ help(matrix, dp, i-1, j);
    int dial= matrix[i][j] + help(matrix, dp, i-1, j+1);
    int diar= matrix[i][j] + help(matrix, dp, i-1,j-1);
    return dp[i][j]=min(up, min(dial, diar));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int res=1e8;
        for(int i=0; i<n; i++){
            res=min(res,help(matrix, dp, n-1,i));
        }
        return res;
    }
};