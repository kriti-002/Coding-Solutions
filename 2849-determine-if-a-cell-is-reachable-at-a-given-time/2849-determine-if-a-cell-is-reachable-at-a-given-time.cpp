class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(abs(sx-fx) ==0 and abs(sy-fy)==0 and t==1) return false;
        return t>= max(abs(sx-fx), abs(sy-fy));
    }
};