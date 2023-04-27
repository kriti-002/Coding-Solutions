//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    char help(int f[], int z){
        int count=0;
        for(int j=25;j>=0;j--){
            if(f[j]!=0){
                count += f[j];
                if(count>=z){
                return (j+'a');
            }
        }
    }
    return 'a';
    }
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        // Code here
        vector<char> res;
        for(auto q: queries){
            if(q[0]=="1"){
                int idx=stoi(q[1]);
                s[idx]= q[2][0];
            }else{
                int f[26]={0};
                int x= stoi(q[1]);
                int y= stoi(q[2]);
                int z= stoi(q[3]);
                for(int i=x; i<=y; i++){
                    f[s[i]-'a']++;
                }
            res.push_back(help(f,z));
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends