class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int l=nums[0],h=nums[0];
        for(int i=1;i<n;i++){
            l=min(l,nums[i]);
            h=max(h,nums[i]);
        }
        while(l<h){
            int m=(l+h)/2;
            int count=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=m){
                    count++;
                    i++;
                }
            }
            if(count>=k){
                h=m;
            }
            else{
                l=m+1;
            }
            
        }
        return l;
    }
};