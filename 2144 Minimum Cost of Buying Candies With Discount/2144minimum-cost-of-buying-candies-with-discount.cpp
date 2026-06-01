class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size()==1) return cost[0];
        sort(cost.begin(),cost.end(), greater<int>());
        int i=0,j=1;
        int ans=0;
        while(j<cost.size()){
            ans+=cost[i]+cost[j];
            i+=3;
            j+=3;
        }
        if(i<cost.size()){
            ans+=cost[i];
        }
        return ans;
    }
};