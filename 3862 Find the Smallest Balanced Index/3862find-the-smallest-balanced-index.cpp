class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prod(n);
        vector<long long> sum(n);
        sum[0]=nums[0];
        for(int i=1;i<n;i++){
            sum[i]=nums[i]+sum[i-1];
        }
        prod[n-1]=nums[n-1];
        long long min_sum=sum[n-1];
        for(int i=n-2;i>=0;i--){
            long long val=min_sum/max(nums[i],1);
            if(prod[i+1]>val){
                prod[i]=min_sum+1;
            }
            else{
                prod[i]=nums[i]*prod[i+1];
            }
        }
        for(int i=0;i<n;i++){
            long long right_prod=(i<n-1)?prod[i+1]:1;
            long long left_sum=(i>0)?sum[i-1]:0;
            if(left_sum==right_prod){
                return i;
            }
        }
        return -1;
        
    }
};