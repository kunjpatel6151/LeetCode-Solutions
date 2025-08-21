class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,combination,ans,target);
        return ans;
    }

    void solve(vector<int>& candidates,int i,vector<int>& combination,vector<vector<int>>& ans,int target){
        if(target==0){
            ans.push_back(combination);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1]){
                continue;
            }
            if(candidates[j]>target){
                break;
            }
            combination.push_back(candidates[j]);
            solve(candidates,j+1,combination,ans,target-candidates[j]);
            combination.pop_back();
        }
    }
};