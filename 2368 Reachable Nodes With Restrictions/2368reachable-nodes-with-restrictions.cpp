class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& visited,unordered_set<int>& st){
        if(st.count(node)) return;
        visited[node]=true;
        for(int neigh: adj[node]){
            if(!visited[neigh] && !st.count(neigh)){
                dfs(neigh,adj,visited,st);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        unordered_set<int> st;
        for(int node:restricted){
            st.insert(node);
        }
        dfs(0,adj,visited,st);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]) count++;
        }
        return count;
    }
};