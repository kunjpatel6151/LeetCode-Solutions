class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<k){
                return -1;
            }
            s.insert(nums[i]);
        }
        int count=s.size();
        if(s.count(k)){
            count--;
        }
        return count;

    }
};