class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        if(n<3){
            return -1;
        }
        int low=0, high=n-1;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(arr[mid-1] <= arr[mid] and arr[mid+1] <= arr[mid]){
                return mid;
            }else if(arr[mid-1]< arr[mid] and arr[mid+1] > arr[mid]){
                low=mid;
            }else{
                high=mid;
            }
        }
        return -1;
    }
};