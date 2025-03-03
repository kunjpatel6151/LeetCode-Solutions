class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> v1,v2,v3;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                v1.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                v2.push_back(nums[i]);
            }
            else{
                v3.push_back(nums[i]);
            }
        }
        vector<int> ans;
        for(int i=0;i<v1.size();i++){
            ans.push_back(v1[i]);
        }
        for(int i=0;i<v2.size();i++){
            ans.push_back(v2[i]);
        }
        for(int i=0;i<v3.size();i++){
            ans.push_back(v3[i]);
        }
        return ans;
        
       
    }
};