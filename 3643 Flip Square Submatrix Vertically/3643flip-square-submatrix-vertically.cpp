class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int ur=x,uc=y;
        int lr=x+k-1,lc=y+k-1;
        while(ur<lr){
            for(int j=uc;j<=lc;j++){
                swap(grid[ur][j],grid[lr][j]);
            }
            ur++;
            lr--;
        }
        return grid;
    }
};