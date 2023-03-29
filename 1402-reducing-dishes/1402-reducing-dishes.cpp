class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        int res=0, j=1, tmp=0;
        for(int i=sat.size()-1; i>=0; i--){
            if(tmp+ sat[i] <0) break;
            tmp+=sat[i];
            res+= tmp;
        }
        return res;
    }
};