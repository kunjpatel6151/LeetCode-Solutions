class Solution {
public:

    bool solve(vector<int>& ans, vector<bool>& used, int index, int n){
        if(index==ans.size()){
            return true;
        }
        if(ans[index]!=0){
            return solve(ans,used,index+1,n);
        }
        for(int i=n;i>=1;i--){
           if(used[i]){
            continue;
           }
           if(i==1){
            ans[index]=i;
           }
           else if(index+i<ans.size() && ans[index+i]==0){
            ans[index]=ans[index+i]=i;
           }
           else{
            continue;
           }
           used[i]=true;
           if(solve(ans,used,index+1,n)){
            return true;
           }
           ans[index]=0;
           if(i>1) ans[index+i]=0;
           used[i]=false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int size=2*n-1;
        vector<int> ans(size,0);
        vector<bool> visited(n+1,false);
        solve(ans,visited,0,n);
        return ans;
        
    }
};