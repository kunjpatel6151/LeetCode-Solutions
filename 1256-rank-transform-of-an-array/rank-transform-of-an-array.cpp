class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       unordered_map<int,vector<int>> mp;
       vector<int> v = arr;
       int n=arr.size();
       for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);        
       }
       sort(v.begin(),v.end());
       vector<int> ans(n,-1);
       int rank=1;
       for(int i=0;i<n;i++){
            bool flag=true;
            for(int x:mp[v[i]]){
                if(ans[x]==-1){
                    ans[x]=rank;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                rank++;
            }
       }
       return ans;
    }
};