//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n=arr.size(), i;
        vector<int> res(n,-1);
        stack<int>s;
        for(i=n-1; i>=0; i--){
            while(!s.empty() and arr[s.top()]  >= arr[i]) s.pop();
            if(s.empty()) res[i]=-1;
            else res[i]=s.top();
            s.push(i);
            
        }
        while(s.size()) s.pop();
        for(i=0;i<n;i++) {
            while(s.size() && arr[s.top()]>=arr[i]) s.pop();
            if(s.size()) {
                if(res[i]==-1) res[i]=s.top();
                else {
                    int index=s.top();
                    if((i-index)<(res[i]-i)) res[i]=index;
                    else if((i-index)==(res[i]-i)) {
                        if(arr[index]<=arr[res[i]]) res[i]=index;
                    }
                }
            }
            s.push(i);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends