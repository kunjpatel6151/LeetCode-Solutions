class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> a(m*n,1);
        long long product=1;
        for(int k=1;k<m*n;k++){
            int i=(k-1)/n;
            int j=(k-1)%n;
            product=(product*grid[i][j])%12345;
            a[k]*=product;
        }
        product=1;
        for(int k=m*n-2;k>=0;k--){
            int i=(k+1)/n;
            int j=(k+1)%n;
            product=(product*grid[i][j])%12345;
            a[k]=(a[k]*product)%12345;
        }
        vector<vector<int>> ans(m, vector<int> (n,1));
        for(int k=0;k<m*n;k++){
            int i=k/n;
            int j=k%n;
            ans[i][j]=a[k];
        }
        return ans;

    }
};