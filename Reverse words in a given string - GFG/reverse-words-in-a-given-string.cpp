//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<char>st;
        string res;
        for(int i=S.length()-1; i>=0; i--){
            if(S[i]!='.'){
                st.push(S[i]);
            }else{
                while(!st.empty()){
                    res+=st.top();
                    st.pop();
                }
                res+='.';
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends