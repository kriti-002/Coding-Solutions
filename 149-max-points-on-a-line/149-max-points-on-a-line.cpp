class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res=0, n=points.size();
        
        if(n<= 2) return n;
        for(int i=0; i<n; i++){
            unordered_map<double, int>mp;
            double slope=0.0; int dup=0;
            for(int j=0; j<n; j++){
                int dy= points[j][1]-points[i][1], dx=points[j][0]-points[i][0];
                if(dx==0 and dy==0){
                    dup++;
                    continue;
                }
                if(dx!=0){
                    slope= dy*(1.0)/dx;
                }else{
                    slope=INT_MAX;
                }
                mp[slope]++;
            }
             if(mp.size()==0) res=dup;
            for(auto x: mp){
                res=max(res,x.second+dup);
            }
        }
       
        return res;
    }
};