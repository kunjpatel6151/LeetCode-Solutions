class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i*i<=right;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=right;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        vector<int> prime;
        for(int i=left;i<=right;i++){
            if(isPrime[i]){
                prime.push_back(i);
            }
        }
        if(prime.size()<2){
            return {-1,-1};
        }
        vector<int> ans(2);
        int m=right-left;
        for(int i=1;i<prime.size();i++){
            if(prime[i]-prime[i-1]<=2){
                ans[0]=prime[i-1];
                ans[1]=prime[i];
                break;
            }
            m=min(prime[i]-prime[i-1],m);
            if(m==prime[i]-prime[i-1]){
                ans[0]=prime[i-1];
                ans[1]=prime[i];
            }
        }
        return ans;
    }
};