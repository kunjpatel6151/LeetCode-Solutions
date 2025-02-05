class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        vector<vector<int>> a;
        int n=nums.size();
        int i=0;
        while(i<n){
            vector<int> b;
            b.push_back(nums[i]);
            int j=i+1;
            while(j<n && nums[j-1]<nums[j]){
                b.push_back(nums[j]);
                j++;
            }
            a.push_back(b);
            i++;            
        }
        int sum=0;
        int ans=0;
        for(int i=0;i<a.size();i++){
            sum=0;
            for(int j=0;j<a[i].size();j++){
                sum+=a[i][j];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};