class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        vector<vector<long long>> dist(m, vector<long long> (n,-1));
        queue<pair<int,int>> q;
        dist[0][0]=1;
        q.push({0,0});
        int d=1;
        vector<pair<int,int>> dir ={{0,-1},{-1,0},{0,1},{1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
        while(!q.empty()){
            int N=q.size();
            for(int i=0;i<N;i++){
                auto [nx,ny] = q.front();
                q.pop();
                for(auto &[dx, dy]:dir){
                    int x=nx+dx;
                    int y=ny+dy;
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0 && dist[x][y]==-1){
                        dist[x][y]=d+1;
                        q.push({x,y});
                    }
                }
            }
            d+=1;
        }
        return dist[m-1][n-1];
    }
};