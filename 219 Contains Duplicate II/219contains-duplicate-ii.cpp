class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        int l=0,r=0;
        while(r<n){
            if(mp.find(nums[r])==mp.end()){
                mp[nums[r]]++;
            }
            else{
                return true;
            }
            if(r-l>=k){
                mp[nums[l]]--;
                if(mp[nums[l]]<=0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return false;
    }
};