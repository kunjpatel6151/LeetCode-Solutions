class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int m=INT_MAX,M,ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    M=nums[i]+nums[j]+nums[k];
                    m=min(m,abs(target-M));
                    if(m==abs(target-M)){
                        ans=M;
                    }
                }
            }
        }
        return ans;
    }
};