class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int> comp;
                bfs(i,adj,comp,visited);
                bool flag=true;
                for(auto neigh:comp){
                    if(adj[neigh].size()!=comp.size()-1){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans++;
                }
            }
        }
        return ans;
    }

    void bfs(int node,vector<vector<int>>& adj,vector<int>& comp,vector<bool>& visited){
        queue<int> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            comp.push_back(f);
            for(int neighbor:adj[f]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor]=true;
                }
            }
        }
    }
};