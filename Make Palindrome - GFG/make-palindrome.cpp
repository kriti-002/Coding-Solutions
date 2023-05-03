//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            string s=arr[i];
            reverse(s.begin(),s.end());
            if(mp.find(s)!=mp.end() and mp[s]>0){
                mp[s]--;
            }else mp[arr[i]]++;
        }
        for(auto m :mp){
            if(m.second>0){
                string s=m.first;
                reverse(s.begin(),s.end());
                if(s!=m.first) return 0;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends