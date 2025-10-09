class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& dp){
        if(dp[node]!=-1) return dp[node];
        int count=1;
        for(int child:adj[node]){
            count+=dfs(child,adj,dp);
        }
        return dp[node]=count;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(parents[i]!=-1){
                adj[parents[i]].push_back(i);
            }
        }
        vector<int> dp(n, -1);
        dfs(0,adj,dp);
        vector<long long> nodes(n,0);
        for(int i=0;i<n;i++){
            if(adj[i].empty()){
                nodes[i]=n-1;
            }
            else if(adj[i].size()==1){
                int count=dp[adj[i][0]];
                int remain=n-1-count;
                if(remain==0){
                    nodes[i]=count;
                }
                else{
                    nodes[i]=1LL*count*remain;
                }
            }
            else{
                int count1=dp[adj[i][0]];
                int count2=dp[adj[i][1]];
                int remain=n-1-count1-count2;
                nodes[i]=1;
                if(count1!=0){
                    nodes[i]*=count1;
                }
                if(count2!=0){
                    nodes[i]*=count2;
                }
                if(remain!=0){
                    nodes[i]*=remain;
                }
            }
        }
        long long ans=0;
        for(long long x:nodes){
            ans=max(ans,x);
        }
        return count(nodes.begin(),nodes.end(),ans);

    }
};