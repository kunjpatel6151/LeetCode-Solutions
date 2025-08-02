class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> mp1,mp2,total;
        int n=basket1.size();
        int global_min=INT_MAX;
        
        for(int i=0;i<n;i++){
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
            total[basket1[i]]++;
            total[basket2[i]]++;
            global_min=min(global_min,min(basket1[i],basket2[i]));
        }

        for(auto& p:total){
            if(p.second % 2 != 0){
                return -1; // impossible to balance
            }
        }

        vector<int> left, right;
        for(auto& p : total){
            int x = p.first;
            int diff = mp1[x] - mp2[x];
            if(diff > 0){
                for(int i = 0; i < diff / 2; i++) left.push_back(x);
            } else if(diff < 0){
                for(int i = 0; i < -diff / 2; i++) right.push_back(x);
            }
        }

        sort(left.begin(), left.end());               // smallest first
        sort(right.rbegin(), right.rend());           // largest first

        long long cost = 0;
        for(int i = 0; i < left.size(); i++){
            int k1 = left[i];
            int k2 = right[i];
            int swap_cost = min({k1, k2, 2 * global_min});
            cost += 1LL * swap_cost;
        }

        return cost;
    }
};
