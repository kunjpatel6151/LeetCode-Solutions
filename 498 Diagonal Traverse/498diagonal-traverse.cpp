class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> ans;
        if(m==1){
            for(int j=0;j<n;j++){
                ans.push_back(mat[0][j]);
            }
            return ans;
        }
        if(n==1){
            for(int i=0;i<m;i++){
                ans.push_back(mat[i][0]);
            }
            return ans;
        }
        bool LtoR=true;
        int i=0,j=-1;
        int count=0;
        while(count<(m*n)){
            if(LtoR){
                if(i==m){
                    i--;
                    j+=2;
                }
                else{
                    j++;
                }
                while(i>=0 && j<n){
                    ans.push_back(mat[i][j]);
                    count++;
                    i--;
                    j++;
                }
            }
            else{
                if(j==n){
                    j--;
                    i+=2;
                }
                else{
                    i++;
                }
                while(j>=0 && i<m){
                    ans.push_back(mat[i][j]);
                    count++;
                    i++;
                    j--;
                }
            }
            LtoR=!LtoR;
        }
        return ans;
    }
};