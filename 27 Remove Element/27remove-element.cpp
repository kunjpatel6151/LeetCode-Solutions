class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),k=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        int count=k;
        while(count<n){
            nums[count]=-1;
            count++;
        }
        return k;
    }
};