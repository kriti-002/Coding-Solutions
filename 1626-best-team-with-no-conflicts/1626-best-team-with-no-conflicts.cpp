class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int res=0, n=scores.size();
        vector<int>dp(n, 0);
        vector<vector<int>>tmp;
        for(int i=0; i<n; i++){
            tmp.push_back({-ages[i], -scores[i]});
        }
        sort(tmp.begin(), tmp.end());
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--){
                if(-tmp[i][1] <= -tmp[j][1]){
                    dp[i]=max(dp[i], dp[j]-tmp[i][1]);
                }
            }
        }
        for(int i=0; i<n; i++){
            res=max(res,dp[i]);
        }
        return res;
    }
};