class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binary_search(nums.begin(), nums.end(), target)== false) return {-1,-1};
        int low= lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        int high= upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        return {low, high-1};
    }
};