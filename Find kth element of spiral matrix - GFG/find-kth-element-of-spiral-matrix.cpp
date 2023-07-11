//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    vector<int> spiral(int a[MAX][MAX], int n, int m){
        vector<int>ans;
         int l=0,r=m-1, t=0,d=n-1;

         while(l<=r and t<=d){
             for(int j=l;j<=r;j++){
                 ans.push_back(a[t][j]);
             }
             t++;
             for(int i=t;i<=d;i++){
                 ans.push_back(a[i][r]);
             }
             r--;
             for(int j=r;j>=l;j--){
                 ans.push_back(a[d][j]);
             }
             d--;
             for(int i=d;i>=t;i--){
                 ans.push_back(a[i][l]);
             }
             l++;
    
         }
         return ans;
    }
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		vector<int>res=spiral(a,n,m);
 		if(k> n*m) return 0;
 		return res[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends