class Solution {
public:
    int minval(vector<vector<int>>& pre,int k){
        int m=pre.size();
        int n=pre[0].size();
        int M=INT_MAX;
        for(int i=k-1;i<m;i++){
            for(int j=k-1;j<n;j++){
                int sum=pre[i][j];
                if(i-k>=0) sum-=pre[i-k][j];
                if(j-k>=0) sum-=pre[i][j-k];
                if(i-k>=0 && j-k>=0){
                    sum+=pre[i-k][j-k];
                }
                M=min(M,sum);
            }
        }
        return M;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        int smallest=mat[0][0];
        vector<vector<int>> pre(m, vector<int> (n,0));
        pre[0][0]=mat[0][0];
        for(int i=1;i<m;i++){
            pre[i][0]=pre[i-1][0]+mat[i][0];
            smallest=min(smallest,mat[i][0]);
        }
        for(int j=1;j<n;j++){
            pre[0][j]=pre[0][j-1]+mat[0][j];
            smallest=min(smallest,mat[0][j]);
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                pre[i][j]=mat[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
                smallest=min(smallest,mat[i][j]);
            }
        }
        if(smallest>threshold) return 0;
        int l=1,r=max(m,n);
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(minval(pre,mid)<=threshold){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};