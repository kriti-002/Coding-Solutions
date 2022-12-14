//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long res = 0;
        if(n == 0) return res;
            
        stack<long long> st;
        
        for(int i=0; i<n; ++i) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                long long last = st.top();
                st.pop();
                long long curr = arr[last] * (st.empty() ? i : (i - st.top() - 1));
                res = max(res, curr);
            }
            st.push(i);
        }
        while(!st.empty()) {
            long long last = st.top();
            st.pop();
            long long curr = arr[last] * (st.empty() ? n : (n - st.top() -1));
            res = max(res, curr);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends