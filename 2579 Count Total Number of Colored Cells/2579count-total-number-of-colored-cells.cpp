class Solution {
public:
    long long coloredCells(int n) {
        long long N=n;
        long long ans=1 + 2*N*(N-1);
        return ans;
    }
};