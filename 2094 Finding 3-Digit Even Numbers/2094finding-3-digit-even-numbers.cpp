class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> v;
        vector<int> h(10,0);
        int n=digits.size();
        for(int i=0;i<n;i++){
            h[digits[i]]++;
        }
        for(int i=100;i<999;i+=2){
            v.push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            int num=v[i];
            vector<int> mp(10,0);
            while(num>0){
                int digit=num%10;
                num/=10;
                mp[digit]++;
            }
            bool flag=true;
            for(int i=0;i<10;i++){
                if(mp[i]>h[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(v[i]);
            }
        }
        return ans;


    }
};