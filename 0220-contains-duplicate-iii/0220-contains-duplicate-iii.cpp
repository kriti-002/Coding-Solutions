class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long>w;
        for(int i=0;i<nums.size();i++){
            if(i>k)w.erase(nums[i-k-1]);
            auto s=w.lower_bound((long)nums[i]-t);
            if(s!=w.end() && *s<=(long)nums[i]+t) return true;
            w.insert(nums[i]);
        }        
        return false;
    }
};