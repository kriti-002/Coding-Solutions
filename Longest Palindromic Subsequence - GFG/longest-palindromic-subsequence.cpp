//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int help(int i, int j, string &A, string &B, vector<vector<int>>&dp){
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(A[i]== B[j])dp[i][j]= 1+ help(i-1,j-1,A,B, dp);
        else dp[i][j]= max(help(i-1,j,A,B,dp), help(i,j-1,A,B,dp));
        
        return dp[i][j];
    }
    int lcs(string A, string B){
        int n=A.length();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return help(n-1,n-1,A,B,dp);
    }
  public:
    int longestPalinSubseq(string A) {
        //code here
        string B= A;
        reverse(B.begin(), B.end());
        return lcs(A,B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends