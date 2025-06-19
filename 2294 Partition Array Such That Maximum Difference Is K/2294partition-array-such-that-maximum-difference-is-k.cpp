class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> v;
        int count=0;
        for(int i=0;i<n;i++){
            if(v.empty()){
                v.push_back(nums[i]);
            }
            else if(nums[i]-v[0]<=k){
                v.push_back(nums[i]);
            }
            else{
                count++;
                v.clear();
                v.push_back(nums[i]);
            }
        }
        if(!v.empty()){
            count++;
        }
        return count;
        
    }
};