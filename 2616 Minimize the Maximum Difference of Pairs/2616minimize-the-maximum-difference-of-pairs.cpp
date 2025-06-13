class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=nums[n-1]-nums[0],ans=0;
        while(l<=r){
            int d=l+(r-l)/2;
            int count=0;
            for(int i=1;i<n;i++){
                if(d>=nums[i]-nums[i-1]){
                    count++;
                    i++;
                }
            }
            if(count>=p){
                ans=d;
                r=d-1;
            }
            else{
                l=d+1;
            }
        }
        return ans;
    }
};