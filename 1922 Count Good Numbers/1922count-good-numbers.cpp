class Solution {
public:
    const int MOD=1000000007;
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2;
        if(n%2==1){
            even++;
        }
        return (count(5,even)*count(4,odd))%MOD;
    }

    long long count(long long ans,long long x){
        if(x==0){
            return 1;
        }
        else if(x%2==0){
            return count((ans*ans)%MOD,x/2);
        }
        else{
            return (ans*count(ans,x-1))%MOD;
        }
    }
};