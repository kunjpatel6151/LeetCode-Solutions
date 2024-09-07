class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int a[n+1];
        a[0]=0;
        for(int i=1;i<=n;i++){
            a[i]=gain[i-1]+a[i-1];
        }
        int m=INT_MIN;
        for(int i=0;i<=n;i++){
            m=max(m,a[i]);
        }
        return m;
    }
};