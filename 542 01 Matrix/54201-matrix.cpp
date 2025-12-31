class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int INF=1e9;
        vector<vector<int>> dp(m, vector<int> (n,INF));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<dir.size();i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(dp[nx][ny]>dp[x][y]+1){
                        dp[nx][ny]=dp[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return dp;
    }
};