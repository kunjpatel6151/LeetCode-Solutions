class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();
        int ans=-1;
        int val=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(capacity[i]>=itemSize){
                val=min(val,capacity[i]);
                if(capacity[i]==val){
                    ans=i;
                }
            }
        }
        return ans;
    }
};