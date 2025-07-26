class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            bool flag=true;
            int k=i%n;
            int j=(i+1)%n;
            while(j!=i && flag){
                if(nums[k]>nums[j]){
                    flag=false;
                    break;
                }
                k=(k+1)%n;
                j=(j+1)%n;
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};