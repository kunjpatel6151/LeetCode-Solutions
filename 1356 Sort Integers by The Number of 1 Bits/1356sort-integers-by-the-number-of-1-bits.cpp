class Solution {
public:
    int f(int n){
        int count=0;
        while(n>0){
            count+=n&1;
            n>>=1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> a;
        for(int x:arr){
            a.push_back({f(x),x});
        }
        sort(a.begin(),a.end());
        vector<int> ans;
        for(auto& p:a){
            ans.push_back(p.second);
        }
        return ans;
    }
};