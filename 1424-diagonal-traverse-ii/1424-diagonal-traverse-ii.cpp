class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        unordered_map<int,vector<int>>mp;
        for(int i=nums.size()-1; i>=0; i--){
            for(int j=0; j<nums[i].size(); j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        int curr=0;
        while(mp.find(curr)!= mp.end()){
            for(auto x: mp[curr]) res.push_back(x);
            curr++;
        }
        
        
        return res;
    }
};