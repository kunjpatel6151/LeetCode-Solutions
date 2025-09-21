class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        if(n==1 && m==1){
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        if(n==1){
            if(mat[0][0]>mat[0][1]){
                ans.push_back(0);
                ans.push_back(0);
                return ans;
            }
            if(mat[0][m-1]>mat[0][m-2]){
                ans.push_back(0);
                ans.push_back(m-1);
                return ans;
            }
            for(int j=1;j<m-1;j++){
                if(mat[0][j]>mat[0][j-1] && mat[0][j]>mat[0][j+1]){
                    ans.push_back(0);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        if(m==1){
            if(mat[0][0]>mat[1][0]){
                ans.push_back(0);
                ans.push_back(0);
                return ans;
            }
            if(mat[n-1][0]>mat[n-2][0]){
                ans.push_back(n-1);
                ans.push_back(0);
                return ans;
            }
            for(int i=1;i<n-1;i++){
                if(mat[i][0]>mat[i-1][0] && mat[i][0]>mat[i+1][0]){
                    ans.push_back(i);
                    ans.push_back(0);
                    return ans;
                }
            }
        }
        if(n>=m){
            int l=0,r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                int maximum=-1;
                int index=-1;
                for(int j=0;j<m;j++){
                    if(mat[mid][j]>maximum){
                        maximum=mat[mid][j];
                        index=j;
                    }
                }
                if(((mid-1)>=0 && mat[mid-1][index]<mat[mid][index]) && ((mid+1)<n && mat[mid+1][index]<mat[mid][index])){
                    ans.push_back(mid);
                    ans.push_back(index);
                    break;
                }
                else if((mid-1)<0 && ((mid+1)<n && mat[mid+1][index]<mat[mid][index])){
                    ans.push_back(mid);
                    ans.push_back(index);
                    break;
                }
                else if((mid+1)>=n && ((mid-1)>=0 && mat[mid-1][index]<mat[mid][index])){
                    ans.push_back(mid);
                    ans.push_back(index);
                    break;
                }
                else if(((mid-1)>=0 && mat[mid-1][index]>mat[mid][index])){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return ans;
        }
        else{
            int l=0,r=m-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                int maximum=-1;
                int index=-1;
                for(int i=0;i<n;i++){
                    if(mat[i][mid]>maximum){
                        maximum=mat[i][mid];
                        index=i;
                    }
                }
                if(((mid-1)>=0 && mat[index][mid-1]<mat[index][mid]) && ((mid+1)<m && mat[index][mid+1]<mat[index][mid])){
                    ans.push_back(index);
                    ans.push_back(mid);
                    break;
                }
                else if((mid-1)<0 && ((mid+1)<m && mat[index][mid+1]<mat[index][mid])){
                    ans.push_back(index);
                    ans.push_back(mid);
                    break;
                }
                else if((mid+1)>=m && ((mid-1)>=0 && mat[index][mid-1]<mat[index][mid])){
                    ans.push_back(index);
                    ans.push_back(mid);
                    break;
                }
                else if(((mid-1)>=0 && mat[index][mid-1]>mat[index][mid])){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return ans;
        }
    }
};