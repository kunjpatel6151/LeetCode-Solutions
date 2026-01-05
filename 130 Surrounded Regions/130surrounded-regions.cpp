class Solution {
public:

    vector<int> dirx = {0,-1,0,1};
    vector<int> diry = {-1,0,1,0};

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int newi=i+dirx[k];
            int newj=j+diry[k];
            if(newi>=0 && newi<board.size() && newj>=0 && newj<board[0].size() && board[newi][newj]=='O' && !visited[newi][newj]){
                dfs(board,visited,newi,newj);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && !visited[0][j]){
                dfs(board,visited,0,j);
            }
            if(board[m-1][j]=='O' && !visited[m-1][j]){
                dfs(board,visited,m-1,j);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !visited[i][0]){
                dfs(board,visited,i,0);
            }
            if(board[i][n-1]=='O' && !visited[i][n-1]){
                dfs(board,visited,i,n-1);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};