class Solution {
public:
    int rob(vector<int>& nums) {
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
};