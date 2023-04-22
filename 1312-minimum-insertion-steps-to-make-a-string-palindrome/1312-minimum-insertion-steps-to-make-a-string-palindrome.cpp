class Solution {
    bool isPalin(string s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i++]!= s[j--]) return false;
        }
        return true;
    }
    int longestPalindromeSubseq(string s) {
        string t= s;
        reverse(t.begin(), t.end());
        int m=s.length();
        
        vector<vector<int>>dp(m+1, vector<int>(m+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]== t[j-1]) dp[i][j]= 1+ dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][m];
    }
public:
    int minInsertions(string s) {
        //longest palindrome can be achieved when str + reverse(str): insertion= length(str)
        //already a palindrome-> return 0
        //
        if(isPalin(s)) return 0;
        int x= longestPalindromeSubseq(s);
        return s.length()-x;
    }
};