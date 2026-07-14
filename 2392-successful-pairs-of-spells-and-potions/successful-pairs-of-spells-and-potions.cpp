class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=potions.size();
        vector<int> ans;
        for(int x:spells){
            int y=binary_search(potions,x,success);
            int val=max(0,n-y);
            ans.push_back(val);
        }
        return ans;
    }

    int binary_search(vector<int>& potions, int x, long long success){
        int l = 0;
        int r = potions.size();

        while (l < r) {
            int m = l + (r - l) / 2;
            long long p = 1LL * potions[m] * x;

            if (p < success)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};