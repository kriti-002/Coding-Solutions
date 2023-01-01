class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n=pairs.size();
        vector<int> dp(n, 1);
        
        for(int j=1; j<n; j++){
            for(int i=0; i<j; i++){
                if(pairs[i][1]< pairs[j][0]) dp[j]= max(dp[j], dp[i]+1);
            }
        }
        int res=0;
        for(auto x: dp) res=max(res, x);
        return res;
    }
};