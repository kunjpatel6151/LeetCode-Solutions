class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        bool sign=true;
        if(dividend>=0 && divisor<0) sign=false;
        if(dividend<0 && divisor>0) sign=false;
        long long n=llabs((long long)dividend);
        long long d=llabs((long long)divisor);
        long long ans=0;
        while(n>=d){
            long long temp=d;
            long long m=1;
            while(n>=(temp<<1)){
                temp<<=1;
                m<<=1;
            }
            n-=temp;
            ans+=m;
        }
        if(!sign){
            ans=-ans;
        }
        return (int)ans;
    }
};