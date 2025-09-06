class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& v,int i,vector<int>&nums){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        solve(ans,v,i+1,nums);
        v.pop_back();
        solve(ans,v,i+1,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans,v,0,nums);
        return ans;
    }
};