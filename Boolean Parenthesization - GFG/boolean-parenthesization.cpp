//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[202][202][2];
    int help(int i, int j,string&s, bool isTrue){
        if(i > j) return 0;
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        
        int totalWays=0;
        for(int k= i+1; k<j; k+=2){
            int lt=help(i, k-1, s, 1);
            int lf= help(i, k-1, s, 0);
            int rf= help(k+1, j, s, 0);
            int rt= help(k+1, j, s, 1);
            
            if(s[k]=='&'){
                if(isTrue) totalWays+= lt* rt;
                else totalWays+= (lt*rf)+ (lf* rt) +(lf* rf);
            }else if(s[k]=='^'){
                if(isTrue) totalWays+= (lt* rf) + (lf* rt);
                else totalWays+= (lf* rf) + (lt*rt);
            }else if(s[k]=='|'){
                if(isTrue) totalWays+= (lt* rt) + (lf*rt) + (lt*rf);
                else totalWays+= lf*rf;
            }
        }
        dp[i][j][isTrue]=totalWays%1003;
    }
public:
    int countWays(int N, string S){
        // code here
        memset(dp, -1, sizeof(dp));
        return help(0, N-1,S, 1);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends