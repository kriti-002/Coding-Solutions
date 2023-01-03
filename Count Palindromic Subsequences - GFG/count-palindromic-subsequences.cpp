//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod=1e9+7;
    long long int help(int i, int j, string& s, vector<vector<long long int>>&dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==s[j]){
            return dp[i][j]= (1+ help(i, j-1, s, dp)+ help(i+1, j, s, dp))%mod;
        }else{
            return dp[i][j]= (mod+ help(i+1,j,s,dp) + help(i, j-1, s, dp) - help(i+1, j-1, s, dp))%mod;
        }
    }
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int n=str.length();
       vector<vector<long long int>>dp(n, vector<long long int>(n,-1));
       return help(0,n-1,str, dp);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends