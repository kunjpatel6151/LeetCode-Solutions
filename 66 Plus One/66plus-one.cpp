#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool allNines = true;
        for (int i = 0; i < n; i++) {
            if (digits[i] != 9) {
                allNines = false;
                break;
            }
        }
        if (allNines) {
            vector<int> ans(n + 1, 0);
            ans[0] = 1;
            return ans;
        } else {
            int i = n - 1;
            digits[i] += 1;
            while (i > 0 && digits[i] == 10) {
                digits[i] = 0;
                digits[i - 1] += 1;
                i--;
            }
            if (digits[0] == 10) {
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};
