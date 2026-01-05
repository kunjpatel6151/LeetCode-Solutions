class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int M=abs(matrix[0][0]);
        vector<bool> check(n,false); 
        long long sum=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    count++;
                }
                M=min(abs(matrix[i][j]),M);
                sum+=abs(matrix[i][j]);
            }
            if(count%2==0){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]<0){
                        matrix[i][j]*=(-1);
                    }
                }
                check[i]=true;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!check[i]) count++;
        }
        if(count%2!=0){
            return sum-2*M;
        }
        else{
            return sum;
        }

    }
};