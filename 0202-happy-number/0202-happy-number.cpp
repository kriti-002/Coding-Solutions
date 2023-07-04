class Solution {
public:
    bool isHappy(int n) {
        if(n==1) return 1;
        if(n>1 and n<=4) return 0;
        int sum=0;
        while(n >0){
            int rem=n%10;
            sum+=(rem*rem);
            n/=10;
        }
        return isHappy(sum);
    }
};