class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int count=1;
        int range=nums[0];
        int largest=nums[0];
        int i=0;
        while(largest<n-1){
            while(i<=range){
                largest=max(largest,nums[i]+i);
                i++;
            }
            range=largest;
            count++;
        }
        return count;



        return count;
    }
};