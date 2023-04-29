//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here
        int dig[]={9,1,3,5,7};
        long long res=0;
        while(N>0){
            res= res*10+ dig[N%5];
            if(N%5==0) N= N/5-1;
            else N/=5;
        }
        queue<int> q;
        while (res > 0) {
            q.push(res % 10);
            res /= 10;
        }
        res = 0;
        while (!q.empty()) {
            res = res * 10 + q.front();
            q.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends