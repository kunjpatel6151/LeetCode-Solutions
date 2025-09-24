class Solution {
public:
    int MOD=1337;
    int Mod_pow(int a, int x){
        if(x==0){
            return 1;
        }
        a%=MOD;
        if(x%2==0){
            int half=Mod_pow(a,x/2)%MOD;
            return (half*half)%MOD;
        }
        else{
            return (a*Mod_pow(a,x-1))%MOD;
        }
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int x=b.back();
        b.pop_back();
        int part1=Mod_pow(a,x);
        int part2=Mod_pow(superPow(a,b),10);
        return (part1*part2)%MOD;
    }
};