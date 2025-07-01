class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        bool flag=true;
        for(int i=0;i<n;i++){
            set<int> s1,s2;
            for(int j=0;j<n;j++){
                s1.insert(matrix[i][j]);
                s2.insert(matrix[j][i]);
            }
            if(s1.size()!=n || s2.size()!=n){
                flag=false;
                break;
            }
        }
        return flag;
    }
};