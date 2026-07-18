class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> front;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> back;
        int l=0, r=n-1;
        for(int i=0;i<candidates && l<=r;i++){
            front.push({costs[l],l});
            l++;
        }
        for(int i=0;i<candidates && l<=r;i++){
            back.push({costs[r],r});
            r--;
        }
        long long ans=0;
        while(k--){
            if(back.empty() || (!front.empty() && front.top().first<=back.top().first)){
                auto f=front.top();
                front.pop();
                ans+=f.first;
                if(l<=r){
                    front.push({costs[l],l});
                    l++;
                }
            }
            else{
                auto b=back.top();
                back.pop();
                ans+=b.first;
                if(l<=r){
                    back.push({costs[r],r});
                    r--;
                }
            }
        }
        return ans;
    }
    
};