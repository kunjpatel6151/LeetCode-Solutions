class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int size = word.size();
        int n = sequence.size();
        int ans = 0;
        
        for (int i = 0; i <= n - size; ) {
            int count = 0;
            int j = i;
            while (j + size <= n && sequence.substr(j, size) == word) {
                count++;
                j += size;
            }
            ans = max(ans, count);
            if (count > 0) {
                i += 1; // move ahead one char from current start, to check for overlapping
            } else {
                i++;
            }
        }
        
        return ans;
    }
};
