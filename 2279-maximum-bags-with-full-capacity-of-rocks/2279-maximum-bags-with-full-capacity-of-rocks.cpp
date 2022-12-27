class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        int n=rocks.size();
        for(int i=0; i<n; i++) capacity[i]-=rocks[i];
        sort(capacity.begin(), capacity.end());
        
        int full=0;
        for(int i=0; i<n and add>0; i++){
            if(capacity[i]!=0){
                if(add >= capacity[i]) full++;
                add-=capacity[i];
            }else full++;
        }
        return full;
    }
};