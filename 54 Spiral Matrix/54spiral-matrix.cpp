class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        // 0:r 1:d 2:l 3:up
        int direction=0;
        long long count=0,total=n*m;
        vector<int> ans;
        int i=0,j=0;
        while(count<total){
            if(direction==0){
                while(j<m && !visited[i][j]){
                    ans.push_back(matrix[i][j]);
                    visited[i][j]=true;
                    j++;
                    count++;
                }
                j--;
                i++;
            }
            else if(direction==1){
                while(i<n && !visited[i][j]){
                    ans.push_back(matrix[i][j]);
                    visited[i][j]=true;
                    i++;
                    count++;
                }
                i--;
                j--;
            }
            else if(direction==2){
                while(j>=0 && !visited[i][j]){
                    ans.push_back(matrix[i][j]);
                    visited[i][j]=true;
                    j--;
                    count++;
                }
                j++;
                i--;
            }
            else{
                while(i>=0 && !visited[i][j]){
                    ans.push_back(matrix[i][j]);
                    visited[i][j]=true;
                    i--;
                    count++;
                }
                i++;
                j++;
            }
            direction=(direction+1)%4;            
        }
        return ans;
    }
};