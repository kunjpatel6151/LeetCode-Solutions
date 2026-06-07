class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i,j,parent);
                }
            }
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(find(i,parent));
        }
        return n - st.size();
    }

    int find(int x, vector<int>& parent){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x],parent);
    }

    void Union(int x, int y, vector<int>& parent){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px!=py){
            parent[px]=py;
        }
    }
};