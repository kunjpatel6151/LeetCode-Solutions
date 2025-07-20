class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                while(!q.empty()){
                    int f=q.front();
                    q.pop();
                    for(int neighbor:adj[f]){
                        if(!visited[neighbor]){
                            q.push(neighbor);
                            visited[neighbor]=true;
                        }
                    }
                }
                count++;
            }
        }
        return count-1;
    }
};