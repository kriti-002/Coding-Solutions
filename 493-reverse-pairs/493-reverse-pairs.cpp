class Solution {
public:
    int res;
    int reversePairs(vector<int>& nums) {
        if(nums.size()==0) return 0;
        res=0;
        mergeSort(nums, 0, nums.size()-1);
        return res;
    }
    void mergeSort(vector<int>&nums, int start, int end){
        if(start == end) return;
        int mid=start+(end-start)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        countPairs(nums, start, mid, end);
        return;
    }
    void countPairs(vector<int>&nums, int start, int mid, int end){
        int i=start, j=mid+1;
        while(i<=mid and j<=end){
            if((long)nums[i] > (long) 2 * nums[j]){
                res+= (mid - i + 1);
                j++;
            }else{
                i++;
            }
        }
        sort(nums.begin()+start, nums.begin()+end+1);
        return;
    }
};