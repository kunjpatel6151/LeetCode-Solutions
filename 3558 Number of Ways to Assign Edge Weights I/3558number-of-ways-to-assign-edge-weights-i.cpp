class Solution {
public:
    int max_depth=0;
    const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }
    void dfs(int node, int parent, int depth, vector<vector<int>>& adj){
        max_depth=max(max_depth,depth);
        for(int neigh:adj[node]){
            if(neigh!=parent){
                dfs(neigh,node,depth+1,adj);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0,0,adj);
        if(max_depth==0) return 0;
        return power(2,max_depth-1);
    }
};