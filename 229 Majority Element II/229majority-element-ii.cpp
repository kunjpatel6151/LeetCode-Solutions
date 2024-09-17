class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> a;
        int n=nums.size();
        int s=n/3,count=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }
            else{
                if(count>s){
                    a.push_back(nums[i]);
                }
                count=1;
            }
        }
        if(count>s){
            a.push_back(nums[n-1]);
        }
        return a;
    }
};