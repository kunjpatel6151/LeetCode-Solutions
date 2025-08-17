class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        long long k=0;
        bool neg=false;
        bool seendigit=false;
        bool seensign=false;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(!seendigit && !seensign && c==' '){
                continue;
            }
            if(!seendigit && !seensign && (c=='-' || c=='+')){
                if(c=='-'){
                    neg=true;
                }
                seensign=true;
                continue;
            }
            if(c>='0' && c<='9'){
                k=k*10 + (c-'0');
                seendigit=true;

                if(!neg && k>INT_MAX){
                    return INT_MAX;
                }
                if(neg && -k<INT_MIN){
                    return INT_MIN;
                }
            }
            else{
                break;
            }
        }
        if(neg){
            k=-k;
        }
        return (int)k;
    }
};