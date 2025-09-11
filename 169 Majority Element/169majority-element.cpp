class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }

    int solve(vector<int>& nums,int l,int r){
        if(l==r){
            return nums[l];
        }
        int m=l+(r-l)/2;
        int left=solve(nums,l,m);
        int right=solve(nums,m+1,r);
        if(left==right){
            return left;
        }
        else{
            int cl=count(nums,l,r,left);
            int cr=count(nums,l,r,right);
            if(cl>=cr){
                return left;
            }
            else{
                return right;
            }
        }
    }

    int count(vector<int>& nums, int l, int r, int target){
        int count=0;
        for(int i=l;i<=r;i++){
            if(nums[i]==target){
                count++;
            }
        }
        return count;
    }
};