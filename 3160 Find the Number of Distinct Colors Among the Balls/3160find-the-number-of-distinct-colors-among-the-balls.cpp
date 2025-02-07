class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        map<int,int> mp1;
        map<int,int> mp2;
        vector<int> ans;
        int count=0;
        for(int i=0;i<n;i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            if(mp1.find(ball)!=mp1.end()){
                int pcolor=mp1[ball];
                mp2[pcolor]--;
                if(mp2[pcolor]==0){
                    count--;
                }
            }
            mp1[ball]=color;
            if(mp2[color]==0){
                count++;
            }
            mp2[color]++;
            ans.push_back(count);
        }
        return ans;
    }
};