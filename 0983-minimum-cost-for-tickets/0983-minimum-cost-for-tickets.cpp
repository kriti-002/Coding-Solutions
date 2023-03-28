class Solution {
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d=days.size(), c=costs.size();
		vector<int> dp(d+1,0);
		for(int i=d-1;i>=0;i--){
			int ind1=lower_bound(days.begin(),days.end(),days[i]+1)-days.begin();
			int op1=costs[0]+dp[ind1];
			int ind2=lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
			int op2=costs[1]+dp[ind2];
			int ind3=lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
			int op3=costs[2]+dp[ind3];
			dp[i]=min(op1,min(op2,op3));
		}
		return dp[0];
    }
};