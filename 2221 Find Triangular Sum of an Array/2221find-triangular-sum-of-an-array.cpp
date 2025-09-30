class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> v;
        int ans=0;
        for(int i=0;i<n-1;i++){
           if(i==0){
            v=f(nums);
           }
           else{
            v=f(v);
           }
        }
        return v[0];
    }

    vector<int> f(vector<int>& nums){
        vector<int> v;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            int x=prev+nums[i];
            prev=nums[i];
            v.push_back(x%10);
        }
        return v;
    }

};