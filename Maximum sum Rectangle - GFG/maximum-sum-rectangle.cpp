//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int kadane(int tmp[], int n){
        int currSum=0, maxSum=INT_MIN;
        for(int i=0; i<n; i++){
            currSum+=tmp[i];
            maxSum=max(maxSum, currSum);
            if(currSum < 0) currSum=0;
        }
        return maxSum;
    }
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int res=INT_MIN;
        for(int i=0; i<R; i++){
            int tmp[C]={0};
            for(int j=i; j<R; j++){
                for(int k=0; k<C; k++){
                    tmp[k] += M[j][k];
                }
                res=max(res, kadane(tmp, C));
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends