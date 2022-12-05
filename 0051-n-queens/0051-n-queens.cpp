class Solution {
public:
    void help(vector<vector<string>>& res, vector<string>& tmp, vector<int>& lr, vector<int>& ld, vector<int>& ud, int col, int n){
        if(col==n){
            res.push_back(tmp);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(lr[row]==0 and ld[row+ col]==0 and ud[n-1+col-row]==0){
                tmp[row][col]='Q';
                lr[row]=1;
                ld[row+ col]=1;
                ud[n-1+col-row]=1;
                help(res, tmp, lr, ld, ud, col+1, n);
                tmp[row][col]='.';
                lr[row]=0;
                ld[row+col]=0;
                ud[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string> tmp(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            tmp[i]=s;
        }
        vector<int>lr(n, 0), ud(2*n -1, 0),ld(2*n -1, 0);
        help(res, tmp, lr, ld, ud, 0, n);
        return res;
    }
};