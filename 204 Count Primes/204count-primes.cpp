class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n+1,true);
        int count=0;
        for(long long i=2;i<=sqrt(n);i++){
            if(v[i]){
                for(int j=i*i;j<n;j+=i){
                    v[j]=false;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(v[i]) count++;
        }
        return count;
    }
};