class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        set<int> s;
        for(int i=1;i<=100;i++){
            if(isPrime(i)){
                s.insert(i);
            }
        }
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])){
                v.push_back(i);
            }
        }
        int n=v.size();
        return v[n-1]-v[0];
    }

    bool isPrime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
};