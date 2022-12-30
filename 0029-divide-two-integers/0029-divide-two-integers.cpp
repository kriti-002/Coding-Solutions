class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1) return dividend;
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        
        int sign= dividend<0 ^ divisor<0? -1:1;
        long div=abs(dividend),d=abs(divisor),ans=0;
        while(div>=d){
            long temp=d;
            int m=1;
            while(div>=(temp<<1)){
                temp=(temp<<1);
                m=(m<<1);
            }
            ans+=m;
            div-=temp;
        }
        return sign*ans;
    }
};