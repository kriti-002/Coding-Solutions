class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>dp;
        int mid;
        for(int i=0; i<=rowIndex; i++){
            dp.push_back(1);
            mid=dp.size()-2;
            for(int j=mid; j>0; j--){
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp;
    }
};