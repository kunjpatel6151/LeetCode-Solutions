class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int,int> mp;
        for(int x:hand){
            mp[x]++;
        }
        while(!mp.empty()){
            int i=0;
            int k1=-1,k2=-1;
            for(pair<int,int> p:mp){
                if(i==0){
                    k1=p.first;
                    mp[k1]--;
                    if(mp[k1]==0){
                        mp.erase(k1);
                    }
                }
                else{
                    k2=p.first;
                    if((k2-k1)!=1) return false;
                    mp[k2]--;
                    if(mp[k2]==0){
                        mp.erase(k2);
                    }
                    k1=k2;
                }
                i++;
                if(i>=groupSize) break;
            }
            if(i<groupSize) return false;
        }
        return true;
    }
};