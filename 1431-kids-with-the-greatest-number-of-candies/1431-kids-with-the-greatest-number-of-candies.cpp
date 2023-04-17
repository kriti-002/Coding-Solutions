class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>res;
        int maxi= *max_element(candies.begin(), candies.end());
        for(auto c: candies){
            if(c + extraCandies >= maxi) res.push_back(1);
            else res.push_back(0);
        }
        
        
        return res;
    }
};