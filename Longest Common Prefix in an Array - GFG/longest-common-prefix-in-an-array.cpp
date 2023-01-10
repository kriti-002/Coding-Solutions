//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    string help(string s1, string s2){
        int n=max(s1.length(), s2.length());
        string res;
        for(int i=0; i<n; i++){
            if(s1[i]==s2[i]){
                res+=s1[i];
            }else break;
        }
        return res;
    }
  public:
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string res=arr[0];
        for(int i=1; i<N; i++){
            res=help(res, arr[i]);
        }
        return res.length()==0 ? "-1" : res; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends