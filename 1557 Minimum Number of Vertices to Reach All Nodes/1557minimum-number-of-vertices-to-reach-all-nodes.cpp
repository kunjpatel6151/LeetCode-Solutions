class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> ans;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(indegree[i]==0 && !visited[i]){
                ans.push_back(i);
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
};