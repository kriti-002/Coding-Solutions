class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res1, res2;
        vector<vector<int>> res;
        unordered_set<int>s1;
        unordered_set<int>s2;
        for(auto x:nums1) s1.insert(x);
        for(auto x:nums2) s2.insert(x);
        
        for(auto x:s1){
           if(s2.find(x)==s2.end()) res1.push_back(x);
        }
         for(auto x:s2){
           if(s1.find(x)==s1.end()) res2.push_back(x);
        }
        res.push_back(res1);
        res.push_back(res2);
        return res;
    }
};