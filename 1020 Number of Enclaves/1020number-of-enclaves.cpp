class Solution {
public:
    vector<int> dx={0,-1,0,1};
    vector<int> dy={-1,0,1,0};
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==1 && !visited[nx][ny]){
                dfs(nx,ny,grid,visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(i,0,grid,visited);
            }
            if(grid[i][n-1]==1 && !visited[i][n-1]){
                dfs(i,n-1,grid,visited);
            }
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1 && !visited[0][j]){
                dfs(0,j,grid,visited);
            }
            if(grid[m-1][j]==1 && !visited[m-1][j]){
                dfs(m-1,j,grid,visited);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};