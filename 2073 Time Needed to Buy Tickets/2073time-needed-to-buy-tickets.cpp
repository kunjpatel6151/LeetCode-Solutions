class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int time=0;
        while(tickets[k]!=0){
            int index=q.front();
            q.pop();
            tickets[index]--;
            if(tickets[index]){
                q.push(index);
            }
            time++;
        }
        return time;
    }
};