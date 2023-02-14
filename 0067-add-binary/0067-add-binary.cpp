class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int m=a.length(), n=b.length(), carry=0;
        int i=m-1, j=n-1;
        while(carry or i>=0 or j>=0){
            int e1= i>=0? a[i--]-'0': 0, e2= j>=0? b[j--]-'0': 0;
            int sum=e1+e2+carry;
            carry=sum/2;
            res=to_string(sum%2)+res;
        }
        if(carry) res="1"+res;
        return res;
    }
};