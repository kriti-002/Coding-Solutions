class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>used1(9,vector<int>(9,0)), used2(9,vector<int>(9,0)), used3(9,vector<int>(9,0));
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]!='.'){
                    int l = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][l] or used2[j][l] or used3[k][l])
                        return false;
                    used1[i][l] = used2[j][l] = used3[k][l] = 1;
                    
                }
            }
        }
        return true;
    }
};