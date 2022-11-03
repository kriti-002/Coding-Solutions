class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left=1, right=1,res=nums[0], n=nums.size();
        for(int i=0; i<n; i++){
            left *= nums[i];
            right *=nums[n-1-i];
            res=max(res, max(left,right));
            if(left==0) left=1;
            if(right==0) right=1;
        }
        return res;
    }
};