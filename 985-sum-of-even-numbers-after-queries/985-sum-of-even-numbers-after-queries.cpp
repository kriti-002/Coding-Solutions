class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(), q=queries.size();
        int sum=0;
        for(auto x: nums){
            if(x%2==0) sum+=x;
        }
        vector<int>res;
        for(int i=0; i<q; i++){
            int val=queries[i][0], idx=queries[i][1];
            if(nums[idx]% 2==0) sum-=nums[idx];
            nums[idx]+=val;
            if(nums[idx]%2==0) sum+=nums[idx];
            res.push_back(sum);
        }
        return res;
    }
};