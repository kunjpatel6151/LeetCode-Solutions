class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> h(501,0);
        for(int i=0;i<nums.size();i++){
            h[nums[i]]++;
        }
        for(int i=0;i<=500;i++){
            if(h[i]%2!=0) return false;
        }
        return true;
    }
};