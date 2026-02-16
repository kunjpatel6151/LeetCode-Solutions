class Solution {
public:
    int reverseBits(int n) {
        string s=DtoB(n);
        solve(s);
        return (int)BtoD(s);
    }

    void solve(string &s){
        if(s.size()==1){
            return;
        }
        int l=0,r=s.size()-1;
        int m=l+(r-l)/2;;
        string right=s.substr(l,m+1);
        string left=s.substr(m+1);
        solve(right);
        solve(left);
        s=left+right;
    }

    

    string DtoB(int n){
        string s(32,'0');
        for(int i=31;i>=0;i--){
            if(n & 1){
                s[i]='1';
            }
            n>>=1;
        }
        return s;
    }

    long long BtoD(string s){
        long long num=0;
        for(int i=0;i<32;i++){
            num<<=1;
            if(s[i]=='1'){
                num+=1;
            }
            
        }
        return num;
    }
};