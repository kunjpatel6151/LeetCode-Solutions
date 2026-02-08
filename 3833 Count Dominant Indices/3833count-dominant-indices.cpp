class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> sufix(n);
        sufix[n-1]=nums[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--){
            sufix[i]=sufix[i+1]+nums[i];
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]>(float)(sufix[i+1]/(n-i-1))){
                ans++;
            }
        }
        return ans;
    }
};