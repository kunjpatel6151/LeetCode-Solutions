class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int i=0, ans=0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int day=1;i<n || !pq.empty();day++){
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;

    }
};