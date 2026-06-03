class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sl=landStartTime[i];
                int el=sl + landDuration[i];
                int sw=waterStartTime[j];
                int ew=sw + waterDuration[j];
                if(sw>=el){
                    ans=min(ans,ew);
                }
                else if(sl>=ew){
                    ans=min(ans,el);
                }
                else{
                    if(sl<=sw){
                        if(el>=sw){
                            ans=min(ans,el+waterDuration[j]);
                        }
                        else{
                            ans=min(ans,ew);
                        }
                    }
                    else{
                        if(ew>=sl){
                            ans=min(ans,ew+landDuration[i]);
                        }
                        else{
                            ans=min(ans,el);
                        }
                    }
                }
            }
        }
        return ans;

    }
};