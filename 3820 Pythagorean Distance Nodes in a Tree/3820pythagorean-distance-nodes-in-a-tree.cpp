class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> distx(n,-1);
        vector<int> disty(n,-1);
        vector<int> distz(n,-1);
        bfs(x,distx,adj);
        bfs(y,disty,adj);
        bfs(z,distz,adj);
        int ans=0;
        for(int i=0;i<n;i++){
            int d1=distx[i];
            int d2=disty[i];
            int d3=distz[i];
            vector<long long> dist={d1,d2,d3};
            sort(dist.begin(),dist.end());
            long long left= dist[0]*dist[0] + dist[1]*dist[1];
            long long right= dist[2]*dist[2];
            if(left==right){
                ans++;
            }
        }
        return ans;
    }

    void bfs(int i, vector<int>& dist, vector<vector<int>>& adj){
        queue<int> q;
        q.push(i);
        dist[i]=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(int x:adj[f]){
                if(dist[x]==-1){
                    dist[x]=dist[f]+1;
                    q.push(x);
                }
            }
        }
    }
};