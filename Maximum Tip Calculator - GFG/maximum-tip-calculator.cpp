//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    long long maxTip(int a[], int b[], int n, int x, int y) {
        // code here
       vector<pair<int,int>>v;
       for(int i = 0;i<n;i++){
            v.push_back({a[i]-b[i],i});
        }
        sort(v.rbegin(),v.rend());
        long long ans =0;
        for(int i = 0;i<n;i++){
            if(v[i].first >= 0){
                if(x){
                    ans += a[v[i].second];
                    x--;
                }
                else{
                    ans += b[v[i].second];
                    y--;
                }
            }
            else if (v[i].first < 0){
                if(n-i <= y){
                    ans += b[v[i].second];
                    y--;
                }
                else{
                    ans += a[v[i].second];
                    x--;
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Solution obj;
        auto ans = obj.maxTip(a, b, n, x, y);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends