//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalin(int i, int j, string& s){
        while(i<j){
            if(s[i++]!= s[j--]) return false;
        }
        return true;
    }
    int help(int i, int j, string &str, vector<vector<int>>&dp){
        int n=str.length();
        if(i>=j) return 0;
        if(isPalin(i,j,str)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        for(int k=i; k<j; k++){
            if(isPalin(i,k,str)){
                int tmp= 1+ help(k+1, j, str, dp);
                mini=min(mini, tmp);
            }
        }
        return dp[i][j]= mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n =str.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return help(0, n-1,str, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends