class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),i=0,k=0,count=1;
        while(i<n){
            count=1;
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count>=2){
                nums[k]=nums[i];
                nums[k+1]=nums[i];
                k+=2;
            }
            else{
                nums[k]=nums[i];
                k++;
            }
            i+=count;
        }
        return k;
    }
};