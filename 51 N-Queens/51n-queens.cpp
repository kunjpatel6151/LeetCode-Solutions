class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> combination(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            combination[i]=s;
        }
        solve(ans,combination,0,n);
        return ans;
    }

    void solve(vector<vector<string>>& ans,vector<string>& combination,int j,int n){
        if(j==n){
            ans.push_back(combination);
            return;
        }
        for(int i=0;i<n;i++){
            if(canPlace(combination,i,j,n)){
                combination[i][j]='Q';
                solve(ans,combination,j+1,n);
                combination[i][j]='.';
            }
        }
    }

    bool canPlace(vector<string>& combination,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(i==row){
                continue;
            }
            if(combination[i][col]=='Q'){
                return false;
            }
        }

        for(int j=0;j<n;j++){
            if(j==col){
                continue;
            }
            if(combination[row][j]=='Q'){
                return false;
            }
        }

        int i=row,j=col;
        while(i<n && j<n){
            if(i!=row && j!=col && combination[i][j]=='Q'){
                return false;
            }
            i++;
            j++;
        }
        i=row,j=col;
        while(i>=0 && j>=0){
            if(i!=row && j!=col && combination[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }

        i=row,j=col;
        while(i<n && j>=0){
            if(i!=row && j!=col && combination[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }

        i=row,j=col;
        while(i>=0 && j<n){
            if(i!=row && j!=col && combination[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }

        return true;
    }
};