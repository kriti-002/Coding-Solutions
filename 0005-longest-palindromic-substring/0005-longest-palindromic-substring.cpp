class Solution {
public:
    string longestPalindrome(string s) {
        string t=s;
        reverse(t.begin(), t.end());
        int n=s.length(), m=t.length();
        int dp[n+1][m+1];
        int res=0; string result="";
        
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 or j==0) dp[i][j]=0;
                else if(s[i-1]==t[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                    if(dp[i][j]> res){
                        string temp = s.substr(i-dp[i][j], dp[i][j]) ;
                        
                        string revtemp =string(temp.rbegin(),temp.rend());
                        if(revtemp==temp){
                            res = dp[i][j] ;
                            result = temp ;
                        }
                    }
                }else dp[i][j]=0;
            }
        }
        return result;     
    }
};