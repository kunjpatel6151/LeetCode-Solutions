class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        bool flag=true;
        for(int i=0;i<n/3;i++){
            int d1=nums[3*i+1]-nums[3*i];
            int d2=nums[3*i+2]-nums[3*i+1];
            int d3=nums[3*i+2]-nums[3*i];
            if(d1>k || d2>k || d3>k){
                flag=false;
                break;
            }
        }
        vector<vector<int>> ans;
        if(!flag){
            return ans;
        }
        for(int i=0;i<n/3;i++){
            vector<int> v;
            v.push_back(nums[3*i]);
            v.push_back(nums[3*i+1]);
            v.push_back(nums[3*i+2]);
            ans.push_back(v);
        }
        return ans;
        
    }
};