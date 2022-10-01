class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
		vector<int> dp(n+2,0);
		dp[n]=1;
		for(int i=n-1;i>=0;i--){
			int one=0,two=0;
			if(s[i]!='0'){
				one=dp[i+1];
				string str;
				str+=s[i];
				str+=s[i+1];
				if(stoi(str)<=26) two=dp[i+2];
			}
			dp[i]=one+two;
		}
		return dp[0];
    }
};