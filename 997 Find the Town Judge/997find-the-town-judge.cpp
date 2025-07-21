class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n);
        vector<int> h(n,0);
        for(int i=0;i<trust.size();i++){
            int u=trust[i][0];
            int v=trust[i][1];
            adj[u-1].push_back(v-1);
            h[v-1]++;
        }
        set<int> s;
        for(int i=0;i<n;i++){
            if(adj[i].size()==0){
                s.insert(i);
            }
        }
        int count=0;
        int ans;
        for(int i=0;i<n;i++){
            if(h[i]==n-1 && s.count(i)){
                count++;
                ans=i;
            }
        }
        if(count==1){
            return ans+1;
        }
        else{
            return -1;
        }
    }
};