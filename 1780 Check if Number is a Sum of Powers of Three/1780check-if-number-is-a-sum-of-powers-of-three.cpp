class Solution {
public:
    bool checkPowersOfThree(int n) {
        set<long long> s;
        for(int i=0;i<=16;i++){
            s.insert(pow(3,i));
        }
        bool flag=true;
        int num=n;
        while(num>0){
            bool found=false;
            for(auto itr=s.rbegin();itr!=s.rend();itr++){
                long long x= *itr;
                if(num>=x){
                    num-=x;
                    s.erase(x);
                    found=true;
                    break;
                }
            }
            if(!found){
                flag=false;
                break;
            }
        }
        return flag;
    }
};