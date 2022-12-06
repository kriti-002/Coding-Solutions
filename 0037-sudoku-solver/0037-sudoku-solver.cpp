class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        help(board);
    }
    bool help(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='.'){
                    for(char c='1'; c<='9'; c++){
                        if(valid(i, j,c,board)){
                            board[i][j]=c;
                            if(help(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool valid(int r, int c, char ch, vector<vector<char>>&board){
        for(int i=0; i<9; i++){
            if(board[i][c]== ch) return false;
            if(board[r][i]==ch) return false;
            if(board[3*(r/3) + i/3][3*(c/3) + i%3]== ch) return false;
        }
        return true;
    }
};