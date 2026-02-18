class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        int m=grid.size();
        int n=grid[0].size();
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int nx=x+dir[i].first;
            int ny=y+dir[i].second;
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1' && !visited[nx][ny]){
                dfs(nx,ny,grid,visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    ans++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return ans;
    }
};