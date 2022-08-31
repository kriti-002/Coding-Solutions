class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        bool p1=false, p2=false, p3=false;
        for(int i=0; i<n; i++){
            if(triplets[i][0]==target[0] and triplets[i][1]<=target[1] and triplets[i][2]<= target[2]) p1=true;
            if(triplets[i][1]==target[1] and triplets[i][0]<= target[0] and triplets[i][2]<= target[2]) p2=true;
            if(triplets[i][2]==target[2] and triplets[i][0]<=target[0] and triplets[i][1]<= target[1]) p3=true;
        }
        
        return p1 and p2 and p3;
    }
};