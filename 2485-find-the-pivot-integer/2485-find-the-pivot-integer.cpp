class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        int from1toN= (n*(n+1))/2;
        
        int leftSum=0, rightSum=0;
        int i=1, j=n;
        while(i<j){
            int mid= i+(j-i)/2;
            if(mid * mid == from1toN) return mid;
            else if(mid * mid <from1toN) i=mid+1;
            else j=mid-1;
        }
        return -1;
    }
};