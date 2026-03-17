class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> prefix(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    if(matrix[i][j]==1){
                        prefix[i][j]=1;
                    }
                    else{
                        prefix[i][j]=0;
                    }
                    continue;
                }
                if(matrix[i][j]==1){
                    prefix[i][j]=1+prefix[i-1][j];
                }
                else{
                    prefix[i][j]=0;
                }
            }
        }
       
        int ans=0;
        for(int i=0;i<m;i++){
            vector<int> row=prefix[i];
            sort(row.begin(),row.end(), greater<int>());
            for(int j=0;j<n;j++){
                ans=max(ans,(j+1)*row[j]);
            }
        }
        return ans;
    }
        
};