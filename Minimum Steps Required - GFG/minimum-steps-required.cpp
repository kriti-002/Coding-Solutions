//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int a=0, b=0, n=str.length();
    for(int i=0; i<n; i++){
        if(str[i]=='a' and str[i+1]=='b') a++;
        else if(str[i]=='b' and str[i+1]=='a') b++;
    }
    return max(a,b)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends