class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        int n=s.size();
        string a=s;
        bool flag=false;
        char c='0';
        for(int i=0;i<n;i++){
            if(a[i]!='9'){
                c=a[i];
                flag=true;
                break;
            }
        }
        if(flag){
            for(int i=0;i<n;i++){
                if(a[i]==c){
                    a[i]='9';
                }
            }
        }
        string b=s;
        if(b[0]=='1'){
            flag=false;
            for(int i=1;i<n;i++){
                if(b[i]!='0' && b[i]!='1'){
                    c=b[i];
                    flag=true;
                    break;
                }
            }
            if(flag){
                for(int i=0;i<n;i++){
                    if(b[i]==c){
                        b[i]='0';
                    }
                }
            }
        }
        else{
            c=b[0];
            for(int i=0;i<n;i++){
                if(b[i]==c){
                    b[i]='1';
                }
            }
        }
        long long d1=stoi(a);
        long long d2=stoi(b);
        return d1-d2;
    }
};