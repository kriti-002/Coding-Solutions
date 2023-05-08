class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0, n=mat.size();
        for(int i=0; i<n; i++){
            if(i== n-i-1){
                sum+=mat[i][i];
            }else{
                sum+=mat[i][i]+mat[i][n-i-1];
            }
        }
        return sum;
    }
};