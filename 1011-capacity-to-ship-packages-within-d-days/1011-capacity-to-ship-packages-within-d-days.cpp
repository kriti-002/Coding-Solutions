class Solution {
    bool isTrue(vector<int>&weights, int c, int days){
        int d=1, curr=0;
        for(auto x: weights){
            curr+=x;
            if(curr > c){
                d++;
                curr=x;
            }
        }
        return d<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int tot=0, maxload=0;
        for(auto x: weights){
            tot+=x;
            maxload=max(maxload, x);
        }
        int low=maxload, high=tot;
        while(low<high){
            int mid= low+(high-low)/2;
            if(isTrue(weights, mid, days)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};