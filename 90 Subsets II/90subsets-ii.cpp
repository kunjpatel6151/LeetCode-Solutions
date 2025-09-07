class Solution {
public:
    void solve(set<vector<int>>& ans, vector<int>& v, int i,vector<int>& nums){
        if(i==nums.size()){
            if(!ans.count(v)){
                ans.insert(v);
            }
            return;
        }
        v.push_back(nums[i]);
        solve(ans,v,i+1,nums);
        v.pop_back();
        solve(ans,v,i+1,nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> v;
        solve(ans,v,0,nums);
        vector<vector<int>> a;
        for(vector<int> n:ans){
            a.push_back(n);
        }
        return a;
    }
};