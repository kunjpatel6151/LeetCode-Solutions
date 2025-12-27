class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> useRoom(n,0);
        priority_queue<int, vector<int>, greater<int>> rooms;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq; 
        // end time & room
        for(int i=0;i<n;i++){
            rooms.push(i);
        }
        for(int i=0;i<meetings.size();i++){
            long long start=meetings[i][0];
            long long end=meetings[i][1];
            while(!pq.empty() && pq.top().first<=start){
                rooms.push(pq.top().second);
                pq.pop();
            }
            if(!rooms.empty()){
                pq.push({end,rooms.top()});
                useRoom[rooms.top()]++;
                rooms.pop();
            }
            else{
                long long time=pq.top().first;
                long long room=pq.top().second;
                pq.pop();
                long long newend=end-start+time;
                pq.push({newend,room});
                useRoom[room]++;
            }
        }
        int m=0;
        for(int x:useRoom){
            m=max(x,m);
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(useRoom[i]==m){
                ans=i;
                break;
            }
        }
        return ans;
    }
};