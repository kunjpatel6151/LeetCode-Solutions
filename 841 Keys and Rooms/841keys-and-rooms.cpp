class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int count=0;
        queue<int> q;
        q.push(0);
        vector<bool> visited(n,false);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(!visited[f]){
                count++;
                visited[f]=true;
                for(int key:rooms[f]){
                    q.push(key);
                }
            }
        }
        if(count==n){
            return true;
        }
        else{
            return false;
        }

    }
};