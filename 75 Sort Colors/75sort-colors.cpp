class Solution {
public:
    void sortColors(vector<int>& nums) {
        int temp,k;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            k=i;
            for(int j=i+1;j<n;j++){
                if(nums[k]>nums[j]){
                    k=j;
                }
            }
            temp=nums[i];
            nums[i]=nums[k];
            nums[k]=temp;
        }
    }
};