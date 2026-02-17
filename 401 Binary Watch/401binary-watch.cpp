class Solution {
public:
    void solve(int i,int h, int m, int t, vector<pair<int,int>>& v){
        if(h>=12 || m>=60){
            return;
        }
        if(t==0){
            v.push_back({h,m});
            return;
        }
        if(i>=10 || t<0){
            return;
        }
        if(i<4){
            solve(i+1,h+pow(2,i),m,t-1,v);
            solve(i+1,h,m,t,v);
        }
        else{
            solve(i+1,h,m+pow(2,i-4),t-1,v);
            solve(i+1,h,m,t,v);
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        int h=0,m=0;
        vector<pair<int,int>> v;
        solve(0,h,m,turnedOn,v);
        vector<string> ans;
        for(auto& p:v){
            string s=set_time(p.first,p.second);
            ans.push_back(s);
        }
        return ans;
    }

    string set_time(int h, int m){
        string hour=to_string(h);
        string min;
        if(m<10){
            min="0"+to_string(m);
        }
        else{
            min=to_string(m);
        }
        string t=hour+":"+min;
        return t;
    }
};