//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int help(int n, int k, vector<vector<int>>&dp){
        int res= INT_MAX;
        if(n==1 or k==0 or k==1) return k;
        if(dp[n][k]!=-1) return dp[n][k];
        for(int i=1; i<=k; i++){
            int Break= help(n-1, i-1, dp);
            int notBreak= help(n, k-i, dp);
            int maxi=max(Break, notBreak)+1;
            res=min(res, maxi);
            dp[n][k]=res;
        }
        return dp[n][k];
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
        return help(n, k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends