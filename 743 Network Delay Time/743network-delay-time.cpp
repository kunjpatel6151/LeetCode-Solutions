class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u-1].push_back({v-1,w});
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
            > pq;
        vector<int> dist(n, INT_MAX);
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            int w=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dist[node]<w) continue;
            for(pair<int,int>& p:adj[node]){
                int v=p.first;
                int cost=p.second;
                if(dist[v]>cost+w){
                    dist[v]=cost+w;
                    pq.push({cost+w,v});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};