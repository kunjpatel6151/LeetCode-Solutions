class Solution {
public:
    bool isCycle(vector<vector<int>>& adj,vector<int>& visited,int i){
        if(visited[i]==1){
            return true;
        }
        if(visited[i]==2){
            return false;
        }
        visited[i]=1;
        for(int neigh:adj[i]){
            if(isCycle(adj,visited,neigh)){
                return true;
            }
        }
        visited[i]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(isCycle(adj,visited,i)){
                return false;
            }
        }
        return true;
    }
};