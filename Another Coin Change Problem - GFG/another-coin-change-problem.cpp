//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
    bool help(int i,int K, int target, vector<int>&coins, vector<vector<int>>&dp){
        if(target==0 and K==0) return true;
        if(i< 0 or K==0) return false;
        if(dp[K][target]!=-1) return dp[K][target];
        
        bool notPick=help(i-1,K, target, coins, dp), pick= false;
        if(coins[i]<= target) pick=help(i,K-1, target-coins[i], coins, dp);
        return dp[K][target]= pick or notPick;
        
    }
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<int>>dp(K+1, vector<int>(target+1, -1));
        return help(N-1, K, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends