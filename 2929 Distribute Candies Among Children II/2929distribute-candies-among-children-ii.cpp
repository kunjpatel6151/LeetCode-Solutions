class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        int M1=min(n,limit);
        for(int i=0;i<=M1;i++){
            ans+=max(min(limit,n-i) - max(0,n-i-limit)+1,0);
        }
        return ans;
    }
};