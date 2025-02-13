class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int count=0;
        while(s.size()>=2){
            auto itr=s.begin();
            long long x= *itr;
            itr++;
            long long y = *itr;
            long long z= min(x,y)*2 + max(x,y);
            if(x>=k){
                break;
            }
            s.erase(s.find(x));
            s.erase(s.find(y));
            s.insert(z);
            count++;
        }
        return count;
    }
};