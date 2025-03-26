class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int n=v.size();
        int m=v[(n-1)/2];
        int count=0;
        for(int i=0;i<n;i++){
            int d=abs(m-v[i]);
            if(d%x==0){
                count+=(d/x);
            }
            else{
                return -1;
            }
        }
        return count;
    }
};