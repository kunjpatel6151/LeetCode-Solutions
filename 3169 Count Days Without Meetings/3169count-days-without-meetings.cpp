class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int unvisited=0, temp=1;
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<meetings.size();i++){
            unvisited+=max(0,meetings[i][0]-temp);
            temp=max(temp,meetings[i][1]+1);
            if(temp>days) break;
        }
        return unvisited + max(0,days-temp+1);
    }
};