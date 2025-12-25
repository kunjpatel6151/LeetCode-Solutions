class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1){
            if(grid[0][0]==0) return 0;
            if(grid[0][0]==1) return -1;
            if(grid[0][0]==2) return 0; 
        }
        int total=0,count=0,time=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    count++;
                    total++;
                }
                if(grid[i][j]==1){
                    total++;
                }
            }
        }
        if(total==0) return 0;
        if(count==0) return -1;
        while(!q.empty() && count<total){
            int N=q.size();
            for(int k=0;k<N;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i>0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                    count++;
                }
                if(j>0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                    count++;
                }
                if(i<m-1 && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                    count++;
                }
                if(j<n-1 && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                    count++;
                }
            }
            time++;
        }


        if(count==total) return time;
        else return -1;
    }
};