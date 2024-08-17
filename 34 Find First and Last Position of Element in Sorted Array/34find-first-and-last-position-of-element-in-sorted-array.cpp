class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
            return {-1,-1};
        }
        int i=0,j=n-1,x=0,y=0;
        while(i<n){
            if(nums[i]==target){
                x++;
                break;
            }
            i++;
        }
        while(j>0){
            if(nums[j]==target){
                y++;
                break;
            }
            j--;
        }
        if(x==0 && y==0){
            return {-1,-1};
        }
        else{
            return {i,j};
        }
    }
};