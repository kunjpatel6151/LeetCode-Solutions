class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> flag(nums.size(),false);
        solve(ans,v,nums,flag);
        return ans;
    }

    void solve(vector<vector<int>>& ans, vector<int>& v,vector<int>& nums,vector<int>& flag){
        if(nums.size()==v.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!flag[i]){
                flag[i]=true;
                v.push_back(nums[i]);
                solve(ans,v,nums,flag);
                flag[i]=false;
                v.pop_back();
            }
        }
    }
};