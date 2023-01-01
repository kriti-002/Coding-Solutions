//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    bool help(int i, int j, string A, string B, string C, vector<vector<int>>&dp){
        if(i==0 and j==0) return true;
        if(i< 0 or j<0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        
        bool temp1=false, temp2=false;
        if(i>=1 and A[i-1]==C[i+j-1]) temp1=help(i-1, j, A, B, C, dp);
        if(j>=1 and B[j-1]==C[i+j-1]) temp2= help(i, j-1, A,B,C, dp);
        
        return dp[i][j]=(temp1 or temp2);
        
    }
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int a=A.length(), b=B.length(), c=C.length();
        if(a+b!=c) return false;
        vector<vector<int>>dp(a+1, vector<int>(b+1, -1));
        return help(a,b,A,B, C, dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends