class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int q:queries){
            if(mp[nums[q]].size()>1){
                ans.push_back(f(q,n,mp[nums[q]]));
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }

    int f(int x, int n, vector<int>& v){
        int m = v.size();

        int pos = lower_bound(v.begin(), v.end(), x) - v.begin();

        int prevIdx = v[(pos - 1 + m) % m];
        int nextIdx = v[(pos + 1) % m];

        int d1 = abs(x - prevIdx);
        d1 = min(d1, n - d1);

        int d2 = abs(x - nextIdx);
        d2 = min(d2, n - d2);

        return min(d1, d2);
    }
};