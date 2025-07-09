class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        bool flag=true;
        for(int i=0;i<mat.size();i++){
            int n=mat[i].size();
            for(int j=0;j<n;j++){
                if(mat[i][j]!=mat[i][(j+k)%n]){
                    flag=false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        return flag;
        
    }
};