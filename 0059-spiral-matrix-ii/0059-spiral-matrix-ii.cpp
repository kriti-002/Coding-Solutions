class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count=1;
        vector<vector<int>>res(n, vector<int>(n));
        for(int i=0; i<(n+1)/2; i++){
            for(int j=i; j<n-i; j++){
                res[i][j]=count++;
            }
            for(int j= i+1; j<n-i; j++){
                res[j][n-i-1]=count++;
            }
            for(int j=n-i-2; j>=i; j--){
                res[n-i-1][j]=count++;
            }
            for(int j=n-i-2; j>i; j--){
                res[j][i]=count++;
            }
        }
        return res;
    }
};