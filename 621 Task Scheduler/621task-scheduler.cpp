class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for(int task:tasks){
            mp[task]++;
        }
        priority_queue<int> pq;
        for(pair<int,int> p:mp){
            pq.push(p.second);
        }
        int ans=0;
        while(!pq.empty()){
            int interval=n+1;
            vector<int> v;
            while(interval>0 && !pq.empty()){
                int freq=pq.top();
                pq.pop();
                if(freq>1){
                    v.push_back(freq-1);
                }
                interval--;
                ans++;
            }
            for(int x:v){
                pq.push(x);
            }
            if(pq.empty()){
                break;
            }
            ans+=interval;
        }
        return ans;
    
    }
};