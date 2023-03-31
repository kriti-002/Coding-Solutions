//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            int store=0;
            for(int i=1; i<n; i++){
                int tmp= a[i]+a[i-1];
                if(tmp&1){
                    sort(a.begin()+store, a.begin()+i, greater<int>());
                    store=i;
                }
            }
            sort(a.begin()+store, a.end(), greater<int>());
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends