class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int c1,c2,c3,c4;
        c1=c2=c3=c4=0;
        for(int num:nums){
            if(num%2!=0){
                c1++;
            }
        }
        for(int num:nums){
            if(num%2==0){
                c2++;
            }
        }
        bool flag=true;
        for(int num:nums){
            if(flag){
                if(num%2!=0){
                    c3++;
                    flag=!flag;
                }
            }
            else{
                if(num%2==0){
                    c3++;
                    flag=!flag;
                }
            }
        }
        flag=true;
        for(int num:nums){
            if(flag){
                if(num%2==0){
                    c4++;
                    flag=!flag;
                }
            }
            else{
                if(num%2!=0){
                    c4++;
                    flag=!flag;
                }
            }
        }
        int ans=max(c1,c2);
        ans=max(c3,ans);
        ans=max(c4,ans);
        return ans;
    }
};