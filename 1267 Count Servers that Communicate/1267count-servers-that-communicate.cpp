class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool b=false;
                if(grid[i][j]==1){
                    for(int k=0;k<n;k++){
                        if(i==k){
                            continue;
                        }
                        if(grid[k][j]==1){
                            b=true;
                            break;
                        }
                    }
                    if(!b){
                        for(int k=0;k<m;k++){
                            if(k==j){
                                continue;
                            }
                            if(grid[i][k]==1){
                                b=true;
                                break;
                            }
                        }
                    }
                }
                if(b){
                    count++;
                }
            }
        }
        return count;
    }
};