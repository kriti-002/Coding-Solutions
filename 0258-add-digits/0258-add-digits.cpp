class Solution {
public:
    int addDigits(int num) {
        if(num>=0 and num<=9) return num;
        int x=num, sum=0;
        while(x!=0){
            sum+=x%10;
            x/=10;
        }
        return addDigits(sum);
    }
};