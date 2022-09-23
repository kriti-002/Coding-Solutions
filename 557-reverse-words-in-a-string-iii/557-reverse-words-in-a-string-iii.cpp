class Solution {
public:
    string reverseWords(string s) {
       int t=-1, n=s.length();
        for(int i=0; i<=n; i++){
            if(i==n or s[i]==' '){
                int start=t+1, end=i-1;
                //reversal of the substring
                while(start< end){
                    char temp=s[start];
                    s[start]=s[end];
                    s[end]=temp;
                    start++;
                    end--;
                }
                t=i;
            }
        }
        return s;
    }
};