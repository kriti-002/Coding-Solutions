class Solution {
public:
    string baseNeg2(int n) {
        if(n==0) return "0";
        string res="";
        int num=n, r=0;
        while(num){
            int rem= num%(-2);
            if(rem&1) res.push_back('1');
            else res.push_back('0');
            num/=-2;
            if(rem==-1) num++;
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};