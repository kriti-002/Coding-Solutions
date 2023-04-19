//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        vector<int>idx1;
        for(int i=0; i<N; i++){
            if(S[i]=='1') idx1.push_back(i);
        }
        if(idx1.empty()) return false;
        int init=0;
        for(int i=0; i<idx1.size(); i++){
            if(idx1[i]- init > X) return false;
            init= idx1[i]+X+1;
        }
        if(N-1>= init) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends