class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            queue<int> q;
            q.push(i);
            vector<bool> visited(n,false);
            visited[i]=true;
            int count=1;
            while(!q.empty()){
                int f=q.front();
                q.pop();
                for(int neighbor:adj[f]){
                    if(!visited[neighbor]){
                        visited[neighbor]=true;
                        q.push(neighbor);
                        count++;
                    }
                }
            }
            if(count==n){
                return i;
            }
        }
        return -1;
    }
};