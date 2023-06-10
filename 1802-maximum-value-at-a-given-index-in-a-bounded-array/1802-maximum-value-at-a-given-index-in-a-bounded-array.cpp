class Solution {
    long long sum(long long n){
        return (n*(n+1))/2;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        long long l=1,r=maxSum;
        long long ans=1;
        while(l<=r){
            long long mid=(l+r)/2;
            long long left = sum(mid-1);
            if(index>mid-1){
                left += (index-mid+1);
            }
            else left -= sum(mid-1-index);
            long long right = sum(mid-1) ;
            if((n-1-index)>(mid-1)){
                right += (n-1-index-(mid-1));
            }
            else right -= sum(mid-1-(n-1-index));
            if(left+right<=(maxSum-mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }   
        return ans;
    }
};