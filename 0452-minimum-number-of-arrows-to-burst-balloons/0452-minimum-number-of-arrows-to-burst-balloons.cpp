class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res=1;
        int left= points[0][0], right= points[0][1];
        
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<= right and points[i][1] >=left){
                left=min(left, points[i][0]);
                right=min(right, points[i][1]);
            }else{
                res++;
                left=points[i][0]; right=points[i][1];
            }
        }
        return res;
    }
};