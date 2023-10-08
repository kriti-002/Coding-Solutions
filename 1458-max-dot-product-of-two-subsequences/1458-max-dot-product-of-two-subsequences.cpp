class Solution {
    int help(int i, int j, vector<vector<int>>&dp, vector<int>&nums1, vector<int>&nums2){
        int n1=nums1.size(), n2= nums2.size();
        if(i >=n1 or j>=n2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int maxi= INT_MIN;
        int pickBoth= nums1[i]*nums2[j] + help(i+1, j+1, dp, nums1, nums2);
        int pickNums1= help(i+1, j, dp, nums1, nums2);
        int pickNums2= help(i,j+1, dp, nums1, nums2);
        int notPickAny= help(i+1, j+1, dp, nums1, nums2);
        return dp[i][j]= max({maxi,notPickAny, pickBoth, pickNums1, pickNums2});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size(), n2=nums2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        int res=help(0,0,dp, nums1, nums2);
        if(res==0){
            int a = *max_element(nums1.begin(), nums1.end());
            int b = *min_element(nums1.begin(), nums1.end());
           
            int c = *max_element(nums2.begin(), nums2.end());
            int d = *min_element(nums2.begin(), nums2.end());
           
           return max(a*d, b*c);
        }
        return res;
    }
};