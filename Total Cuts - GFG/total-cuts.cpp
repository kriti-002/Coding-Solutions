//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int>suf(N);
        suf[N-1]=INT_MAX;
        for(int i=N-2; i>=0; i--){
            suf[i]= min(suf[i+1], A[i+1]);
        }
        int res=0, leftMax=0;
        for(int i=0; i<N; i++){
            leftMax=max(leftMax, A[i]);
            int sum= leftMax+ suf[i];
            if(sum >= K) res++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends