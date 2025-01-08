class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long ps[n];
        ps[0]=nums[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+nums[i];
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            long long s1=ps[i];
            long long s2=ps[n-1]-ps[i];
            if(s1>=s2){
                count++;
            }
        }
        return count;
    }
};