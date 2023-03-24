//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        map<char, int>mp;
        int maxi=0;
        for(auto ch: S){
            mp[ch]++;
            maxi=max(maxi, mp[ch]);
        }
        int i=0, j=S.length()-1, count=0;
        bool f=1,b=1;
        while(i<=j){
            if(f){
                if(mp[S[i]]==1) i++;
                else{
                    mp[S[i]]--;
                    S.erase(i,1);
                    j--;
                    count++;
                    b=1; f=0;
                }
            }else if(b){
                if(mp[S[j]]==1) j--;
                else{
                    mp[S[j]]--;
                    S.erase(j,1);
                    j--;
                    count++;
                    b=0; f=1;
                }
            }
        }
        if(count&1) reverse(S.begin(), S.end());
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends