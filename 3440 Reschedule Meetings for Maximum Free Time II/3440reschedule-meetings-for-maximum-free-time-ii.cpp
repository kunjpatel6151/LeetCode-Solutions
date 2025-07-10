class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        map<int,int> mp;
        mp[startTime[0]]++;
        mp[eventTime-endTime[n-1]]++;
        for(int i=1;i<n;i++){
            int gap=startTime[i]-endTime[i-1];
            mp[gap]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int length=endTime[i]-startTime[i];
            int l=((i>0)?endTime[i-1]:0);
            int r=((i<n-1)?startTime[i+1]:eventTime);
            int gap1=startTime[i]-l;
            int gap2=r-endTime[i];
            bool flag=false;
            mp[gap1]--;
            mp[gap2]--;
            if(mp[gap1]<=0){
                mp.erase(gap1);
            }
            if(mp[gap2]<=0){
                mp.erase(gap2);
            }
            if((*mp.rbegin()).first>=length){
                flag=true;
            }
            mp[gap1]++;
            mp[gap2]++;
            if(flag){
                ans=max(ans,r-l);
            }
            else{
                ans=max(ans,r-l-length);
            }
        }
        return ans;
    }
};