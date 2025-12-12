class Solution {
public:
    bool canJump(vector<int>& nums) {
        int longest=0;
        for(int i=0;i<nums.size();i++){
            if(i>longest) return false;
            longest=max(longest,i+nums[i]);
            if(longest==nums.size()-1) return true;
        }
        return true;
    }
};