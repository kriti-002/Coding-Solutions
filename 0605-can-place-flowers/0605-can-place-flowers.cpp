class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int count=0;
        for(int i=0; i<f.size(); i++){
            if(f[i]==0){
                bool left=((i==0) or f[i-1]==f[i] ? 1: 0);
                bool right=((i==f.size()-1) or f[i+1]== f[i] ? 1: 0);
                if(left and right){
                    f[i]=1;
                    count++;
                    if(count>=n) return true;
                }
            }
        }
        return count>=n;
    }
};