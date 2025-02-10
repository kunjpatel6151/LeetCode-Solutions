class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int pre=-1,first=-1,last=-1,count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                count++;
                if(count==1) first=i;
                last=i;
            }
            if(nums[i]==0){
                if(count%2==0){
                    ans=max(ans,i-pre-1);
                }
                else{
                    ans=max(ans,max(i-first-1,last-pre-1));
                }
                pre=i;
                count=0;
                first=-1;
                last=-1;
            }
        }
        if(count%2==0){
            ans=max(ans,n-pre-1);
        }
        else{
            ans=max(ans,max(n-first-1,last-pre-1));
        }
        return ans;
    }
};