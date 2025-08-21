class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,0,combination,ans,target);
        return ans;
    }

    void solve(vector<int>& candidates,int i,int sum,vector<int>& combination,vector<vector<int>>& ans,int target){
        if(i<candidates.size()){
            if(candidates[i]+sum==target){
                combination.push_back(candidates[i]);
                ans.push_back(combination);
                combination.pop_back();
            }
            else if(candidates[i]+sum<target){
                combination.push_back(candidates[i]);
                solve(candidates,i,sum+candidates[i],combination,ans,target);
                combination.pop_back();
                solve(candidates,i+1,sum,combination,ans,target);
            }
        }
    }
};