class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int ans=-1;
        for(pair<int,int> p:mp){
            if(p.first==p.second){
                ans=max(ans,p.first);
            }
        }
        return ans;
    }
};