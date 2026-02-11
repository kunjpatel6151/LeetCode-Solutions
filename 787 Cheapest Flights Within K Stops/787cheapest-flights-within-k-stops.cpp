class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int cost=flights[i][2];
            adj[u].push_back({v,cost});
        }
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
            > pq;
        vector<vector<int>> dist(n,vector<int> (k+2,INT_MAX));
        pq.push({0,{src,0}});
        dist[src][0]=0;
        while(!pq.empty()){
            int cost=pq.top().first;
            int node=pq.top().second.first;
            int stop=pq.top().second.second;
            pq.pop();
            if(node==dst) return cost;
            if(stop>k) continue;
            for(pair<int,int>& p:adj[node]){
                if(dist[p.first][stop+1]>p.second+cost){
                    dist[p.first][stop+1]=p.second+cost;
                    pq.push({p.second+cost,{p.first,stop+1}});
                }
            }
        }
        return -1;
    }
};