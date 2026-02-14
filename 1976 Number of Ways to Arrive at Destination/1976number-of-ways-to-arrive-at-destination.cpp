class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1000000007;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
            > pq;
        vector<pair<long long, long long>> dist(n,{LLONG_MAX,0});
        dist[0]={0,1};
        pq.push({0,0});
        while(!pq.empty()){
            int node=pq.top().second;
            long long cost=pq.top().first;
            pq.pop();
            if(dist[node].first<cost) continue;
            for(pair<int,int>& p:adj[node]){
                int v=p.first;
                long long w=p.second;
                if(dist[v].first>w+cost){
                    dist[v]={w+cost,dist[node].second};
                    pq.push({w+cost,v});
                }
                else if(dist[v].first==(w+cost)){
                    long long x=(dist[v].second+dist[node].second)%MOD;
                    dist[v]={w+cost,x};
                }
            }
        }
        return dist[n-1].second;
    }
};