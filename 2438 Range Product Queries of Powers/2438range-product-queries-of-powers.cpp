class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int MOD=1000000007;
        vector<int> power;
        f(n,power);
        vector<long long> prefix(power.size());
        prefix[0]=power[0];
        for(int i=1;i<prefix.size();i++){
            prefix[i]=(prefix[i-1]*power[i])%MOD;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            long long val;
            if(l==0){
                val=prefix[r];
            }
            else{
                long long inv = modPow(prefix[l-1], MOD - 2, MOD);
                val = (prefix[r] * inv) % MOD;
            }
            ans.push_back((int)val);
        }
        return ans;
    }

    void f(int n,vector<int>& v){
        int i=30;
        while(i>=0 && n>0){
            long long p=1LL<<i;
            if(n>=p){
                n-=p;
                v.push_back((int)p);
            }
            i--;
        }
        reverse(v.begin(),v.end());
    }

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
};