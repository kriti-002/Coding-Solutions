//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void help(int i, string S, string&tmp, vector<string>&res){
        if(i== S.size()){
            res.push_back(tmp);
            return;
        }
        for(int j=i; j<S.length(); j++){
            tmp.push_back(S[j]);
            swap(S[i], S[j]);
            help(i+1, S, tmp, res);
            tmp.pop_back();
            swap(S[i], S[j]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>res;
        string tmp="";
        help(0,S, tmp, res);
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends