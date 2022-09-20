class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return max(solve(nums1, nums2), solve(nums2, nums1));
    }
    int solve(vector<int>& nums1, vector<int>& nums2){
        int res = 0;
        for (int start = 0; start < nums2.size(); ++start) {
            int acc = 0;
            for (int i = 0; i < nums1.size() && start + i < nums2.size(); ++i) {
                if (nums1[i] == nums2[start + i]) acc++;
                else acc = 0;
                
                res = max(res, acc);
            }
        }
        return res;
    }
};