class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        long long rev=0, num=x;
        while(num>0){
            int rem=num%10;
            rev= rev*10 + rem;
            num/=10;
        }
        return rev==x;
    }
};