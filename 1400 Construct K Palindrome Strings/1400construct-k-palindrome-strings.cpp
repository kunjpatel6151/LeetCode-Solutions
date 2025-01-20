class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n<k){
            return false;
        }
        int h[26]={0};
        for(char c:s){
            int i=c-'a';
            h[i]++;
        }
        int odd=0,even=0;
        for(int x:h){
            if(x>0){
                if(x%2==0){
                    even++;
                }
                else{
                    odd++;
                }
            }
        }
        if(odd>k){
            return false;
        }
        else{
            return true;
        }
    }
};