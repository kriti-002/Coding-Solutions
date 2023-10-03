class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            count+=(m[nums[i]]-1);
        }
        return count;
    }
};