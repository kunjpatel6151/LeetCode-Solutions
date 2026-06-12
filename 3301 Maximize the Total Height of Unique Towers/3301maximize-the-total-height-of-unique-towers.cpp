class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end(), greater<int> ());
        long long ans=maximumHeight[0];
        for(int i=1;i<maximumHeight.size();i++){
            int x=min(maximumHeight[i],maximumHeight[i-1]-1);
            if(x<=0){
                return -1;
            }
            maximumHeight[i]=x;
            ans+=x;
        }
        return ans;
        
    }
};