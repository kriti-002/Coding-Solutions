class Solution {
public:
    long mod=1000000007;
    int concatenatedBinary(int n) {
        long res=0;
        for(int i=1; i<=n; i++){
            int tmp=(log2(i)+1);
            res= ((res<<tmp)%mod+i)%mod;
        }
        return res;
    }
};