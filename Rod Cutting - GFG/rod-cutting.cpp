//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int help(int price[], vector<vector<int>>&dp, int idx, int N){
        if(idx==0) return N* price[idx];
        if(dp[idx][N]!=-1) return dp[idx][N];
        
        int notPick=0+ help(price, dp, idx-1, N);
        int pick=INT_MIN;
        int len= idx+1;
        if(len<= N){
            pick=price[idx]+help(price,dp, idx, N-len);
        }
        return dp[idx][N]= max(pick, notPick);
    } 
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return help(price,dp, n-1, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends