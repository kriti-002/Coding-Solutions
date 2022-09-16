class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(multipliers.size()+1, vector<int>(multipliers.size()+1));
        for(int i = 0; i < dp.size(); i++){
            dp[i][dp[0].size()-1] = 0;
            dp.back()[i] = 0;
        }
        for(int i = dp.size()-2; i >= 0; i--) {
            for(int j = dp[0].size()-2; j >=0; j--) {
                dp[i][j] = max(multipliers[i]*nums[j] + dp[i+1][j+1],
                                    multipliers[i]*nums[nums.size()-1-(abs(i-j))] + dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};