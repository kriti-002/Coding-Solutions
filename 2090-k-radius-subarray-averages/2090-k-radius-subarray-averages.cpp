class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        
        int n=nums.size();
        vector<int>res(n,-1);
        if(2*k+1 > n) return res;
        
        vector<long long> prefix(n+1,0);
        for(int i=0; i<n; i++){
            prefix[i+1]= prefix[i] + nums[i];
        }
        for(int i=k; i<(n-k); i++){
            long long sum=prefix[i+k+1]- prefix[i-k];
            res[i]=(sum/(2*k+1));
        }
        return res;
    }
};