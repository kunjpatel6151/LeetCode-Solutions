class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3,0);
        for(int x:bills){
            if(x==5){
                change[0]++;
            }
            else if(x==10){
                if(change[0]>0){
                    change[0]--;
                    change[1]++;
                }
                else{
                    return false;
                }
            }
            else{
                if(change[0]>0 && change[1]>0){
                    change[0]--;
                    change[1]--;
                    change[2]++;
                }
                else if(change[0]>2){
                    change[0]-=3;
                    change[2]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};