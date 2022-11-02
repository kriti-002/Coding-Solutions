class Solution {
public:
    int help(vector<int>& nums) {
        int prev2=0, prev=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int pick= nums[i];
            if(i>1) pick +=prev2;
            int notPick= prev;
            
            int curr=max(pick, notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> tmp1, tmp2;
        for(int i=0; i<n; i++){
            if(i!=0) tmp1.push_back(nums[i]);
            if(i!=n-1) tmp2.push_back(nums[i]);
        }
        int res1=help(tmp1), res2=help(tmp2);
        return max(res1, res2);
    }
};