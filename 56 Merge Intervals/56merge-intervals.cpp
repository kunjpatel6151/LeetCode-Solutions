class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            s.insert({intervals[i][0],intervals[i][1]});
        }
        vector<vector<int>> ans;
        auto it=s.begin();
        int x=it->first;
        int y=it->second;
        ++it;
        while(it!=s.end()){
            if(it->first<=y){
                y=max(y,it->second);
            }
            else{
                ans.push_back({x,y});
                x=it->first;
                y=it->second;
            }
            ++it;
        }
        ans.push_back({x,y});
        return ans;
    }
};