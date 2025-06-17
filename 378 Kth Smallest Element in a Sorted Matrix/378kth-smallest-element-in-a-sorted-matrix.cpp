class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int,int> mp;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[matrix[i][j]]++;
            }
        }
        int count=k;
        int ans=0;
        for(pair<int,int>p:mp){
            if(p.second>=count){
                ans=p.first;
                break;
            }
            count-=p.second;
        }
        return ans;
    }
};