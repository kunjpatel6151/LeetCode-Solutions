#include <vector>
#include <algorithm>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i=0;i<n-1;i+=3) {
            if (i+2>=n || nums[i]!=nums[i+1] || nums[i+1]!=nums[i+2]) {
                return nums[i];
            }
        }
        return nums[n-1];
    }
};
