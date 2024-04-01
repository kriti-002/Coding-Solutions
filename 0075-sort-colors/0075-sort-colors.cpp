class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0, o=0,t=0;
        for(auto x: nums){
            switch(x){
                case 0:
                    z++;
                    // break;
                case 1:
                    o++;
                    // break;
                case 2:
                    t++;
                    // break;
                default:
                    break;
            }
        }
        int i=0;
        while(i<z){
            nums[i]=0;
            i++;
        }
        while(i<o){
            nums[i]=1;
            i++;
        }
        while(i<t){
            nums[i]=2;
            i++;
        }
    }
};