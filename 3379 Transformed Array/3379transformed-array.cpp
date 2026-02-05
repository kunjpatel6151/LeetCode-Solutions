class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans[i]=nums[i];
            }
            else if(nums[i]>0){
                int j=(i+nums[i])%n;
                ans[i]=nums[j];
            }
            else{
                int k=abs(nums[i])%n;
                if(i-k>=0){
                    ans[i]=nums[i-k];
                }
                else{
                    ans[i]=nums[n+(i-k)];
                }
            }
        }
        return ans;
    }
};