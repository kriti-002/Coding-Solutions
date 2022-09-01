class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size(); 
        int res=0;
        if(n<3) return 0;
   
        for(int i=0; i<n; i++){
            map<int ,int>mp;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int dx= points[i][0]- points[j][0], dy=points[i][1]-points[j][1];
                int dist= (dx*dx)+ (dy*dy);
                mp[dist]++;
            }
            for(auto x: mp){
            if(x.second > 1){
                res+= (x.second *(x.second-1));
            }
        }
    } 
        return res;
    }
};