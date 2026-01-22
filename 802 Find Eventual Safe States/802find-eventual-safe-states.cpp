class Solution {
public:
    void dfs(int i,vector<vector<int>>& graph,vector<int>& cycle,vector<int>& visited){
        if(visited[i]==1){
            cycle[i]=1;
            return;
        }
        visited[i]=1;
        bool flag=false;
        for(int x:graph[i]){
            if(cycle[x]==0){
                dfs(x,graph,cycle,visited);
            }
            if(cycle[x]==1){
                flag=true;
                break;
            }
        }
        if(flag){
            cycle[i]=1;
        }
        else{
            cycle[i]=2;
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> cycle(n,0); // 0:uncheck 1:cycle 2:nocycle
        for(int i=0;i<n;i++){
            vector<int> visited(n,0); // 0: not visited 1:visited
            if(cycle[i]==0){
                dfs(i,graph,cycle,visited);
            }
            if(cycle[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};