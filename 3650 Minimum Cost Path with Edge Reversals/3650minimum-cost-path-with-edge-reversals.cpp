class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<>
        > pq;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto &[v,w]:adj[u]){
                if(d+w<dist[v]){
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                }
            }

        }
        return dist[n-1]==LLONG_MAX ? -1 : dist[n-1];
            

    }
};