class Solution {
    int help(vector<int>& stoneValue, vector<int>& dp, int i){
        int n=stoneValue.size();
        if(i>=n) return 0;
        if(dp[i]!=INT_MAX) return dp[i];
        
        int pickOne=stoneValue[i]- help(stoneValue, dp, i+1), pickTwo=INT_MIN, pickThree=INT_MIN;
        
        if(i+1< n) pickTwo=stoneValue[i]+ stoneValue[i+1]-help(stoneValue, dp, i+2);
        if(i+2< n) pickThree= stoneValue[i]+stoneValue[i+1] + stoneValue[i+2]- help(stoneValue, dp, i+3);
        
        return dp[i]=max({pickOne, pickTwo, pickThree});
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        //round
        //how much to pick(1,2,3)
        int n=stoneValue.size();
        vector<int>dp(n, INT_MAX);
        int val= help(stoneValue, dp,0);
        if(val >0) return "Alice";
        else if(val <0) return "Bob";
        return "Tie";
    }
};