//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Initial Template for C++

// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        long long int arr[n+2]={0};
        int mod=1e9+7;
        arr[0]= 0;
        arr[1]=1;
        for(int i=2; i<=n; i++){
            arr[i]= (arr[i-1] +arr[i-2])%mod;
        }
        return arr[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends