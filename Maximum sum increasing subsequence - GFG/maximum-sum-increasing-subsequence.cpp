//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int help(int i, int p, int n, int arr[], vector<vector<int>>&dp){
	    if(i==n) return 0;
	    if(dp[i][p+1]!=-1) return dp[i][p+1];
	    int sum= help(i+1, p, n, arr, dp);
	    if(p==-1 or arr[p]< arr[i]){
	        sum=max(sum, arr[i]+ help(i+1, i,n, arr, dp));
	    }
	    return dp[i][p+1]= sum;
	    
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n, vector<int>(n+1, -1));
	    return help(0, -1,n, arr, dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends