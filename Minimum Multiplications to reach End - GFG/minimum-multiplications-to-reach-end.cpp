//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<bool> vis(1e5, 0);
        queue<int>q;
        q.push(start); vis[start]=0;
        int count=0, mod= 1e5;
        
        while(!q.empty()){
            int size= q.size();
            while(size--){
                auto x= q.front(); q.pop();
                if(x== end) return count;
                
                for(int i=0; i<arr.size(); i++){
                    int nextNum= (x* arr[i])%mod;
                    if(!vis[nextNum]){
                        q.push(nextNum);
                        vis[nextNum]=1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends