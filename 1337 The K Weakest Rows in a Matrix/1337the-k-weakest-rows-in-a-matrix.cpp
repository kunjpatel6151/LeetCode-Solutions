class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<bool> Added(n,false);
        bool flag=false;
        vector<int> ans;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(!Added[i]){
                    if(mat[i][j]==0){
                        ans.push_back(i);
                        Added[i]=true;
                        k--;
                    }
                }
                if(k<=0){
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            return ans;
        }
        else{
            for(int i=0;i<n;i++){
                if(k<=0){
                    break;
                }
                if(!Added[i]){
                    ans.push_back(i);
                    k--;
                }
            }   
            return ans;  
        }
        
        
    }
};