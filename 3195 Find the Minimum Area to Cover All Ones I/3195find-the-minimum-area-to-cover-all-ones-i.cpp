class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mx,Mx,my,My;
        mx=n;
        my=m;
        Mx=-1;
        My=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    mx=min(mx,i);
                    my=min(my,j);
                    Mx=max(Mx,i);
                    My=max(My,j);
                }
            }
        }
        int area=(Mx-mx+1)*(My-my+1);
        return area;
    }
};