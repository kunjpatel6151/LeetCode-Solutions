class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        multiset<int> s[82];
        for(int i=0;i<n;i++){
            int num=nums[i];
            int sum=0;
            while(num!=0){
                sum+=(num%10);
                num/=10;
            }
            s[sum].insert(nums[i]);
        }
        int ans=-1;
        for(int i=81;i>=0;i--){
            if(s[i].size()>=2){
                auto itr=s[i].end();
                itr--;
                int x= *itr;
                itr--;
                int y= *itr;
                ans=max(ans,x+y);
            }
        }
        return ans;
    }
};