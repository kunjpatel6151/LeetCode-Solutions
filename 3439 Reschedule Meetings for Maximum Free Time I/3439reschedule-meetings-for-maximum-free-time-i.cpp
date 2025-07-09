class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<long long> gap(n+1);
        gap[0]=startTime[0];
        gap[n]=eventTime-endTime[n-1]; 
        for(int i=1;i<n;i++){
            gap[i]=startTime[i]-endTime[i-1];
        }
        vector<long long> pre(n+2,0);
        for(int i=1;i<=n+1;i++){
            pre[i]=pre[i-1]+gap[i-1];
        }
        long long m=0;
        for(int i=k+1;i<=n+1;i++){
            m=max(m,pre[i]-pre[i-(k+1)]);
        }
        return (int)m;
    }
};