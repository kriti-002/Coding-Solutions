class Solution {
public:
    bool dfs(int i, int j, int idx, vector<vector<char>>&board, string word){
        if(idx== word.length()) return true;
        
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!= word[idx]) return false;
        
        board[i][j]='O';
        bool flag= dfs(i+1, j, idx+1, board, word) || dfs(i-1, j, idx+1, board, word) || dfs(i, j-1, idx+1, board, word) || dfs(i, j+1, idx+1, board, word);
        board[i][j]= word[idx];
        return flag;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        int m= board.size(), n=board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]== word[0] and dfs(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
        
    }
        
};