class Solution {
public:
    int trap(vector<int>& height) {
        int res=0, n=height.size();
        int left=0, right=n-1;
        int lh=INT_MIN, rh=INT_MIN;
        while(left<= right){
            lh=max(lh, height[left]);
            rh=max(rh, height[right]);
            
            if(lh< rh){
                res+=lh-height[left];
                left++;
            }else{
                res+=rh-height[right];
                right--;
            }
        }
        return res;
    }
};