class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int l=j-1;
                int r=j+1;
                int val=matrix[i+1][j];
                if(l>=0){
                    val=min(val,matrix[i+1][l]);
                }
                if(r<n){
                    val=min(val,matrix[i+1][r]);
                }
                matrix[i][j]+=val;
            }
        }
        int ans=matrix[0][0];
        for(int j=1;j<n;j++){
            ans=min(ans,matrix[0][j]);
        }
        return ans;
    }
};