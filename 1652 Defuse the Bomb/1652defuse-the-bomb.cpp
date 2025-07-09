class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans;
        
        if (k == 0) {
            ans.assign(n, 0);
        }
        else if (k > 0) {
            int l = 0;
            int count = k;
            int r = (l + 1) % n;
            int sum = 0;
            
            while (count--) {
                sum += code[r];
                r = (r + 1) % n;
            }
            
            while (l < n) {
                ans.push_back(sum);
                sum -= code[(l + 1) % n];
                sum += code[r];
                l++;
                r = (r + 1) % n;
            }
        }
        else {
            int abs_k = -k;
            int l = 0;
            
            // compute initial window sum of the previous abs_k elements
            int sum = 0;
            int r = (l - 1 + n) % n;
            for (int i = 0; i < abs_k; i++) {
                sum += code[r];
                r = (r - 1 + n) % n;
            }
            
            while (l < n) {
                ans.push_back(sum);
                // remove oldest left neighbor
                sum -= code[(l - abs_k + n) % n];
                // add new left neighbor
                sum += code[l];
                l++;
            }
        }
        return ans;
    }
};
