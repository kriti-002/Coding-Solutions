class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto &x: matrix){
            reverse(x.begin(), x.end());
        }
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
    }
};