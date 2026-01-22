class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> incount(numCourses,0);
        vector<int> ans;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
            incount[v]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(incount[i]==0){
                q.push(i);
            }
        }
        if(q.empty()){
            return ans;
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(int x:adj[f]){
                incount[x]--;
                if(incount[x]==0){
                    q.push(x);
                }
            }
            ans.push_back(f);
        }
        if(ans.size()!=numCourses){
            return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};