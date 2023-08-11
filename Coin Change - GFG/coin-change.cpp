//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long int help(int i, int sum, int coins[], vector<vector<long long int>>&dp){
        if(i==0) return sum%coins[0]==0 ? 1: 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        long long int notPick= help(i-1, sum, coins, dp), pick=0;
        if(coins[i]<= sum) pick= help(i, sum-coins[i], coins, dp);
        return dp[i][sum]= pick + notPick;
        
    }
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(N, vector<long long int>(sum+1, -1));
        return help(N-1, sum, coins, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends