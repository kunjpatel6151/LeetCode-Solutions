class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        int INF=1000001;
        vector<int> a(n,INF);
        a[0]=0;
        for(int i=0;i<restrictions.size();i++){
            int idx=restrictions[i][0];
            int maxVal=restrictions[i][1];
            a[idx]=min(a[idx],maxVal);
        }
        for(int i=1;i<n;i++){
            a[i]=min(a[i],a[i-1]+diff[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            a[i]=min(a[i],a[i+1]+diff[i]);
        }
        int ans=0;
        for(int x:a){
            ans=max(x,ans);
        }
        return ans;
    }
};