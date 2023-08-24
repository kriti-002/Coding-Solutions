//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       string res="";
       int fg=0;
       if(s1[0] == '-'){fg++; s1[0]='0';}
       if(s2[0] == '-'){fg++; s2[0]='0';}
       if(s1=="0" or s2=="0"){return "0";}
       vector<int> val(s1.length() + s2.length(), 0);
       for(int i = s1.length() - 1; i>=0; i--){
           for(int j = s2.length()-1; j>=0; j--){
               val[i+j+1] += (s1[i]-'0')*(s2[j]-'0');
               val[i+j] += val[i+j+1]/10;
               val[i+j+1] %= 10;
           }
       }
       string ans="";
       int i = 0, k=0;
       while(i<val.size() and val[i] == 0){i++;}
       if(fg&1){ans.push_back('-');}
       while(i<val.size()){
           ans.push_back(val[i++]+'0');
       }
       return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends