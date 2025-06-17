class Solution {
public:
    
    vector<vector<int>> findPrimePairs(int n) {
        vector<int>prime=findPrime(n);
        int count=0;
        int N=prime.size();
        vector<vector<int>> ans;
        int l=0,r=N-1;
        while(l<=r){
            int sum=prime[l]+prime[r];
            if(sum==n){
                ans.push_back({prime[l],prime[r]});
                l++;
                r--;
            }
            else if(sum<n){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }

    vector<int> findPrime(int n){
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
    
};