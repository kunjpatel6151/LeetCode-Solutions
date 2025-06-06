class Solution {
public:
    string robotWithString(string s) {
        stack<char> t;
        string ans;
        int n = s.size();

        // Compute suffix minimum characters
        vector<char> min_suf(n + 1);
        min_suf[n] = '{'; // a character greater than 'z'
        for (int i = n - 1; i >= 0; i--) {
            min_suf[i] = min(s[i], min_suf[i + 1]);
        }

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);
            // Write to answer from top of stack while it's <= next suffix min
            while (!t.empty() && t.top() <= min_suf[i + 1]) {
                ans += t.top();
                t.pop();
            }
        }

        // Add any remaining characters from stack
        while (!t.empty()) {
            ans += t.top();
            t.pop();
        }

        return ans;
    }
};
