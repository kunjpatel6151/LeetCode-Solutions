#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, bitwise_or = 0, maxLen = 0;

        while (r < n) {
            while ((bitwise_or & nums[r]) != 0) { // If conflict, shrink window
                bitwise_or ^= nums[l];
                l++;
            }
            bitwise_or |= nums[r]; // Include nums[r] in the subarray
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
