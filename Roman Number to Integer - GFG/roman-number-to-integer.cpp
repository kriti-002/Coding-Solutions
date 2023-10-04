//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
      int value(char v){
       switch(v){
           case 'I':{
            return 1;
           }
           case 'V':{
               return 5;
           }
           case 'X':{
               return 10;
           }
           case 'L':{
               return 50;
           }
           case 'C':{
               return 100;
           }
           case 'D':{
               return 500;
           }
           case 'M':{
               return 1000;
           }
           default:{
               break;
           }
       }
    }
    int romanToDecimal(string &str) {
        // code here
        int result=0;
        for(int i=0; i<str.length()-1; i++){
            if(value(str[i]) >= value(str[i+1])){
                result+=value(str[i]);
            }
            else{
                result-=value(str[i]);
            }
        }
        result+=value(str[str.length()-1]);
        return result;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends