class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        for(auto i: intervals){
            int x=i[0], y=i[1];
            if(y < newInterval[0]) res.push_back(i);
            else if(newInterval[1] < x){
                res.push_back(newInterval);
                newInterval=i;
            }else{
                newInterval[0]=min(newInterval[0],x);
                newInterval[1]=max(newInterval[1],y);
            }
            
        }
        res.push_back(newInterval);
        return res;
    }
};