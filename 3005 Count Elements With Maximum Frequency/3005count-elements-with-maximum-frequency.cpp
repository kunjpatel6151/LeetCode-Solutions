class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> a(101,0);
        for(int x:nums){
            a[x]=a[x]+1;
        }
        int m=0;
        for(int i=1;i<=100;i++){
            m=max(a[i],m);
        }
        int count=0;
        for(int i=1;i<=100;i++){
            if(a[i]==m){
                count++;
            }
        }
        return m*count;
    }
};