class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2) return true;
        
        int changeY=coordinates[1][0]-coordinates[0][0];
        int changeX=coordinates[1][1]-coordinates[0][1];
        for(int i=2; i<coordinates.size(); i++){
            if(changeX * (coordinates[i][0]-coordinates[1][0])!= changeY *(coordinates[i][1]-coordinates[1][1])) return false;
        }
        return true;
    }
};