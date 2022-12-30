//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
       int sign = 1;
       dividend < 0 ? sign = sign*(-1) : sign = sign;
       divisor < 0 ? sign = sign*(-1) : sign = sign;
       
       dividend = abs(dividend);
       divisor = abs(divisor);
       long long t = 0;
       long long cnt = 0;
       
       for (int i = 31 ; i>=0 ; i--){
              if (t + (divisor << i) <= dividend){
                 t = t + (divisor << i); 
                 cnt += (1 << i);
              }   
       }
       return sign < 0 ? -cnt : cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends