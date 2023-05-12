class Solution {
    long long help(int i, vector<vector<int>>& questions, vector<long long>& dp){
        if(i>= questions.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long pick=INT_MIN, notPick= INT_MIN;
        pick= questions[i][0]+ help(i+questions[i][1]+1,questions, dp);
        notPick= help(i+1, questions,dp);
        return dp[i]=max(pick, notPick);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return help(0, questions, dp);
    }
};