class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int cnt=1, last=points[0][1];
        for(int i=0; i<points.size(); i++){
            if(points[i][0] > last){
                cnt++;
                last=points[i][1];
            }
            last=min(last, points[i][1]);
        }
        return cnt;
    }
};