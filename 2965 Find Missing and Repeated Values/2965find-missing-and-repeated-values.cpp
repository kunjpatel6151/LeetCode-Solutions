class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        set<int> s;
        for(int i=0;i<n*n;i++){
            s.insert(i+1);
        }
        int r;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=grid[i][j];
                if(s.count(x)){
                    s.erase(x);
                }
                else{
                    r=x;
                }
            }
        }
        vector<int> ans;
        auto itr=s.begin();
        int x= *itr;
        ans.push_back(r);
        ans.push_back(x);
        return ans;
    }
};