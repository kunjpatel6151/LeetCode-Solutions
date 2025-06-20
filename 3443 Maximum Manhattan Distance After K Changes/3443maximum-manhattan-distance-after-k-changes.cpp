class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        vector<int> dist(n);
        int x=0,y=0;
        int m=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='N'){
                y++;
            }
            else if(c=='S'){
                y--;
            }
            else if(c=='E'){
                x++;
            }
            else{
                x--;
            }
            int d=abs(x)+abs(y);
            dist[i]=d;
            m=max(m,d);
        }
        if(k==0){
            return m;
        }
        int prev=dist[0];
        int inc=0;
        m=dist[1];
        for(int i=1;i<n;i++){
            if(dist[i]<prev && k>0){
                inc+=2;
                k--;
            }
            prev=dist[i];
            dist[i]+=inc;
            m=max(m,dist[i]);
        }
        return m;
    }
};