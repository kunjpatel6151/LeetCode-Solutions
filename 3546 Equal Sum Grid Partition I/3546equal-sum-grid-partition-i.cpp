class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        long long total=0;
        vector<long long> prerow(m,0);
        vector<long long> precol(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prerow[i]+=grid[i][j];
                total+=grid[i][j];
            }
            if(i!=0){
                prerow[i]+=prerow[i-1];
            }
        }
        if(total%2!=0){
            return false;
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                precol[j]+=grid[i][j];
            }
            if(j!=0){
                precol[j]+=precol[j-1];
            }
        }
        for(int i=0;i<m;i++){
            if(2*prerow[i]==total){
                return true;
            }
        }
        for(int j=0;j<n;j++){
            if(2*precol[j]==total){
                return true;
            }
        }
        return false;
        
    }
};