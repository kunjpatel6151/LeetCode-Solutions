class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum=0;
        int m=0;
        for(int x:milestones){
            sum+=(long long)x;
            m=max(m,x);
        }
        long long r=sum-(long long)m;
        return min({r*2+1,sum});
    }
};