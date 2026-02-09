class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
            > pq;
        vector<pair<int,int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
        pq.push({0,{0,0}});
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0]=0;
        while(!pq.empty()){
            int t=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==m-1 && y==n-1){
                return t;
            }
            for(int i=0;i<4;i++){
                int nx=x+dir[i].first;
                int ny=y+dir[i].second;
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int cost=max(abs(heights[x][y]-heights[nx][ny]),t);
                    if(cost<dist[nx][ny]){
                        dist[nx][ny]=cost;
                        pq.push({cost,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};