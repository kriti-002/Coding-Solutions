class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res=0; long long sum=0;
        for(auto x: costs){
            sum+=x;
            if(sum <= coins) res++;
        }
        return res;
    }
};