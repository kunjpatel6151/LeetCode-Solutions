class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones=0;
        for(char c:s){
            if(c=='1') ones++;
        }
        vector<pair<char,int>> runs;
        string t="1" + s + "1";
        for(char c:t){
            if(runs.empty() || runs.back().first!=c){
                runs.push_back({c,1});
            }
            else{
                runs.back().second++;
            }
        }
        int ans=ones;
        for(int i=1;i<runs.size()-1;i++){
            if(runs[i].first=='1' && runs[i-1].first=='0' && runs[i+1].first=='0'){
                ans=max(ans,ones + runs[i-1].second + runs[i+1].second);
            }
        }
        return ans;
    }
};