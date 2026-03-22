class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd=INT_MAX;
        int min_even=INT_MAX;
        int odd=0;
        for(int x:nums1){
            if(x%2==0){
                min_even=min(min_even,x);
            }
            else{
                min_odd=min(min_odd,x);
                odd++;
            }
        }
        bool flag1=true, flag2=true;
        if(min_odd==INT_MAX){
            flag1=false;
        }
        else{
            for(int x:nums1){
                if(x%2==0){
                    if(min_odd>=x){
                        flag1=false;
                        break;
                    }
                }
            }
        }

        if(min_odd==INT_MAX){
            flag2=true;
        }
        else{
            for(int x:nums1){
                if(x%2==1){
                    if(x==min_odd){
                        flag2=false;
                        break;
                    }
                }
            }
        }

        return flag1 || flag2;
    }
};