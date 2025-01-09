class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int t=-nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                if(j>i+1 && nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                if(k<n-1 && nums[k]==nums[k+1]){
                    k--;
                    continue;
                }
                if(nums[j]+nums[k]==t){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]>t){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};