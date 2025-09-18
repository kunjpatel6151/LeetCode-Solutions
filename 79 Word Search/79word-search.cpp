class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    solve(board,word,i,j,1,ans);
                }
                if(ans){
                    break;
                }
            }
            if(ans){
                break;
            }
        }
        return ans;
    }

    void solve(vector<vector<char>>& board,string word,int row,int col,int index,bool &ans){
        if(ans){
            return;
        }
        if(index==word.size()){
            ans=true;
            return;
        }
        char temp=board[row][col];
        board[row][col]='?';
        if(row+1<board.size() && board[row+1][col]==word[index]){
            solve(board,word,row+1,col,index+1,ans);
        }
        if(row-1>=0 && board[row-1][col]==word[index]){
            solve(board,word,row-1,col,index+1,ans);
        }
        if(col+1<board[0].size() && board[row][col+1]==word[index]){
            solve(board,word,row,col+1,index+1,ans);
        }
        if(col-1>=0 && board[row][col-1]==word[index]){
            solve(board,word,row,col-1,index+1,ans);
        }
        board[row][col]=temp;
    }

};