class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m=INT_MAX;
        int M=INT_MIN;
        for(int x:nums){
            m=min(m,x);
            M=max(M,x);
        }
        return gcd(m,M);
    }

    int gcd(int x, int y){
        while(y!=0){
            int temp=y;
            y=x%y;
            x=temp;
        }
        return x;
    }
};