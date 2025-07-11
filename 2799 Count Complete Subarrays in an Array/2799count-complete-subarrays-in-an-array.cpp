class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp1;
        for(int i=0;i<n;i++){
            mp1[nums[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int j=i;
            map<int,int> mp2;
            while(j<n && mp2.size()!=mp1.size()){
                mp2[nums[j]]++;
                j++;
            }
            if(mp2.size()==mp1.size()){
                count+=(n+1-j);
            }
        }
        return count;
    }
};