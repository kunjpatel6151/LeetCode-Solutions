class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                queue<int> q;
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
        return count;

    }
};