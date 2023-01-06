//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int help(int i, int n, int k, int A[], vector<vector<int>>&dp){
        if(i==n or k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int maxi= help(i+1, n, k, A, dp);
        for(int j=i+1; j<n; j++){
            if(A[j] > A[i]) maxi=max(maxi, A[j]-A[i] + help(j+1, n, k-1, A, dp));
        }
        return dp[i][k]=maxi;
    }
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>>dp(N, vector<int>(K+1, -1));
        return help(0,N, K, A, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends